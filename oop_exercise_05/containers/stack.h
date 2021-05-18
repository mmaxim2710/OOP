#ifndef STACK_H_
#define STACK_H_

#include <iterator>
#include <memory>

namespace containers {

    template<class T>
    class stack {
        private:
            struct element;
            size_t size = 0;

        public:
            stack() = default;

        class forward_iterator {
            private:
                element* ptr_;
                friend stack;

            public:
                using value_type = T;
                using reference = T&;
                using pointer = T*;
                using difference_type = std::ptrdiff_t;
                using iterator_category = std::forward_iterator_tag;
                forward_iterator(element* ptr);
                T& operator*();
                forward_iterator& operator++();
                forward_iterator& operator++(int);
                bool operator==(const forward_iterator& other) const;
                bool operator!=(const forward_iterator& other) const;
        };

        forward_iterator begin();
        forward_iterator end();
        T& top();
        void push(const T& value);
        void pop();
        void insert_by_number(size_t nubmer, T& value);
        void insert_by_iterator(forward_iterator insert_iterator, T& value);
        void delete_by_iterator(forward_iterator delete_iterator);
        void delete_by_number(size_t number);
        
        private:
            struct element {
                T value;
                std::unique_ptr<element> next = nullptr;
                forward_iterator next_elem();
            };

        static std::unique_ptr<element> insert_impl(std::unique_ptr<element> current, const T& value);
        std::unique_ptr<element> first_ = nullptr;
    };

    template<class T>
    T& stack<T>::top() {
        if(size == 0) throw std::logic_error("Stack empty");
        return first_->value;
    }

    template<class T>
    typename stack<T>::forward_iterator stack<T>::begin() {
        if(first_ == nullptr) return nullptr;
        return forward_iterator(first_.get());
    } 

    template<class T>
    typename stack<T>::forward_iterator stack<T>::end() {
        return forward_iterator(nullptr);
    }

    template<class T>
    std::unique_ptr<typename stack<T>::element> stack<T>::insert_impl(std::unique_ptr<stack<T>::element> current, const T& value) {
        if(current != nullptr) {
            current->next = insert_impl(std::move(current->next), value);
            return current;
        }
        return std::unique_ptr<element>(new element{value});
    }

    template<class T>
    void stack<T>::delete_by_iterator(containers::stack<T>::forward_iterator delete_iterator) {
        forward_iterator begin = this->begin();
        forward_iterator end = this->end();
        if(delete_iterator == end) throw std::logic_error("End of limit!");
        if(delete_iterator == this->begin()) {
            this->pop();
            return;
        }
        while((begin.ptr_ != nullptr) && (begin.ptr_->next_elem() != delete_iterator)) {
            ++begin;
        }
        if(begin.ptr_ == nullptr) throw std::logic_error("End of limit!");
        begin.ptr_->next = std::move(delete_iterator.ptr_->next);
        size--;
    }

    template<class T>
    void stack<T>::delete_by_number(size_t number) {
        forward_iterator iterator = this->begin();
        for(size_t i = 0; i < number; i++) {
            if(i == number){
                break;
            }
            ++iterator;
        }
        this->delete_by_iterator(iterator);
    }

    template<class T>
    void stack<T>::insert_by_iterator(containers::stack<T>::forward_iterator insert_iterator, T& value) {
        auto temp = std::unique_ptr<element> (new element{value});
        forward_iterator begin = this->begin();
        if (insert_iterator == this->begin()) {
            temp->next = std::move(first_);
            first_ = std::move(temp);
            size++;
            return;
        }
        while((begin.ptr_ != nullptr) && (begin.ptr_->next_elem() != insert_iterator)) {
            ++begin;
        }
        if(begin.ptr_ == nullptr) throw std::logic_error("End of limit");
        temp->next = std::move(begin.ptr_->next);
        begin.ptr_->next = std::move(temp);
        size++;
    }

    template<class T>
    void stack<T>::insert_by_number(size_t number, T& value) {
        forward_iterator iterator = this->begin();
        for(size_t i = 0; i < number; i++) {
            if(i == number) {
                break;
            }
            ++iterator;
        }
        this->insert_by_iterator(iterator, value);
    }

        template<class T>
    void stack<T>::push(const T& value) {
        first_ = insert_impl(std::move(first_), value);
        //last_ = std::move(first_);
        size++;
    }

    template<class T>
    void stack<T>::pop() {
        if(size == 0) throw std::logic_error ("This stack is empty!");
        first_ = std::move(first_->next);
        size--;
    }

    template<class T>
    typename stack<T>::forward_iterator stack<T>::element::next_elem() {
        return forward_iterator(this->next.get());
    }

    template<class T>
    stack<T>::forward_iterator::forward_iterator(containers::stack<T>::element* ptr): ptr_{ptr} {}

    template<class T>
    typename stack<T>::forward_iterator& stack<T>::forward_iterator::operator++() {
        if(ptr_ == nullptr) throw std::logic_error("End of limit");
        *this = ptr_->next_elem();
        return *this;
    }

    template<class T>
    typename stack<T>::forward_iterator& stack<T>::forward_iterator::operator++(int) {
        forward_iterator old = *this;
        ++*this;
        return old;
    }

    template<class T>
    bool stack<T>::forward_iterator::operator==(const forward_iterator& other) const {
        return ptr_ == other.ptr_;
    }

    template<class T>
    bool stack<T>::forward_iterator::operator!=(const forward_iterator& other) const {
        return ptr_ != other.ptr_;
    }

    template<class T>
    T& stack<T>::forward_iterator::operator*() {
        return this->ptr_->value;
    }
}

#endif // STACK_H_