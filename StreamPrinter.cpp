//
// Created by yannick lamprecht on 27.02.17.
//

#include <iostream>
#include <fstream>
#include "StreamPrinter.h"


StreamPrinter::StreamPrinter(std::vector<std::fstream *> files) {
    this->files = files;
}

StreamPrinter::~StreamPrinter() {
    for (std::fstream *stream: files) {
        delete (stream);
    }
}

void StreamPrinter::printFiles() {

    for (std::fstream *stream : files) {
        std::string line;

        if (stream->is_open()) {

            while (!stream->eof()) {
                *stream >> line;
                std::cout << line << std::endl;
                // printing out each line of file
            }
        }
    }
}
