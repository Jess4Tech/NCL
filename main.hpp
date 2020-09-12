#ifndef MAIN_H
#define MAIN_H
#include <iostream>

void TestCompiler(int argc, char *argv[]) {
    std::cout << "Received " << argc-2 << " arguments" << std::endl;
}

void HelpCommand() {
    std::cout << "Commands: " << std::endl
    << "\tcompile: " << std::endl
    << "\t\tCompiles the specified file(s)" << std::endl 
    << "\thelp: " << std::endl
    << "\t\tShows this" << std::endl;
}
#endif