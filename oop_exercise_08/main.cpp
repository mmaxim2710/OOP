#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <memory>
#include <string>
#include "triangle.h"
#include "square.h"
#include "octagon.h"
#include "sub.h"



int main(int args, char* argv[]) {
    if (args < 2) {
        std::cout << "Error, use ./[prog_name] [size of buffer]\n";
        return -1;
    }
    int a = 1;

    long buffer_size = strtol(argv[1], nullptr, 10);
    std::vector<std::shared_ptr<figure::Figure>> buffer;
    buffer.reserve(buffer_size);
    Factory factory;
    std::condition_variable cv;
    std::condition_variable cv2;
    std::string command;
    std::mutex mutex;
    bool done = false;
    std::vector<std::shared_ptr<Sub_Interface>> subs;

    subs.push_back(std::make_shared<Console_Print>());
    subs.push_back(std::make_shared<DocumentPrint>());

    std::thread sub([&]() {
        std::unique_lock<std::mutex> sub_lock(mutex);
        while(!done) {
            cv.wait(sub_lock);
            if (done) {
                cv2.notify_all();
                break;
            }
            for (unsigned int i = 0; i < subs.size(); ++i) {
                subs[i]->output(buffer);
            }
            buffer.resize(0);
            ++a;
            cv2.notify_all();
        }
    });

    while(command != "exit") {
        std::cin >> command;

        if (command == "exit") {

            done = true;
            cv.notify_all();
            break;

        } else if (command == "triangle" || command == "square" || command == "octagon") {

            auto temp = factory.plants[command]->Create_figure(std::cin);
            std::unique_lock<std::mutex> main_lock(mutex);
            buffer.push_back(temp);

            if (buffer.size() == buffer.capacity()) {
                cv.notify_all();
                cv2.wait(main_lock);
            }

        } else std::cout << "no such figure\n";
    }

    sub.join();
    return 0;
}