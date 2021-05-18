#ifndef SUBSCRIBERS_H
#define SUBSCRIBERS_H

class Factory {
public:
    std::map<std::string, std::shared_ptr<Fact_Interface>> plants;
    Factory() {
        plants.emplace("triangle", std::make_shared<Tri_factory>());
        plants.emplace("square", std::make_shared<Squ_factory>());
        plants.emplace("octagon", std::make_shared<Oct_factory>());
    }
};

class Sub_Interface {
public:
    virtual void output(std::vector<std::shared_ptr<figure::Figure>>&) = 0;
    virtual ~Sub_Interface() = default;
};

class Console_Print : public Sub_Interface {
public:
    void output(std::vector<std::shared_ptr<figure::Figure>>& buffer) override {
        for (auto& figure : buffer) {
            figure->print(std::cout);
        }
    }
};

class DocumentPrint : public Sub_Interface {
private:
    int a;
public:
    DocumentPrint() : a(1) {}
    void output(std::vector<std::shared_ptr<figure::Figure>>& buffer) override {
        std::string file_name = std::to_string(a);
        file_name += "_file.txt";
        std::ofstream file;
        file.open(file_name);
        if(!file.is_open())
        {
            file.clear();
            file.open(file_name, std::ios::out);
            file.close();
            file.open(file_name);
        }
        for (auto &figure : buffer) {
            figure->print(file);
        }
        ++a;
    }
};

#endif // SUBSCRIBERS_H