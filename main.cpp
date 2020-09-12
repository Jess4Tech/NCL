#include <iostream>
#include <string.h>
#include "main.hpp" // oops lol

using namespace std;
int main(int argc, char *argv[]) {
  if (argc == 1) {
    HelpCommand();
  } else {
      std::string cmd = argv[1];
      if (cmd == "compile") {
          TestCompiler(argc, argv);
      } else if (cmd == "help") {
          HelpCommand();
      }
  }
}