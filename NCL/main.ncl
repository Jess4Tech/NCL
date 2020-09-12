// Data types
// void, int, bool, float, char, string, object

// Variable declaration
// (modifiers) (name): (type) = (value)
(static, public) test_var: int = 12;

// Function declaration
// (modifiers) (return type) (name): (args) { (body) }
(static, private) int test_func: (int num1, int num2) {
  return num1 + num2
}

// Class declaration
// (modifiers) class (name): (extends) { (body) }
(public) class test_class: {
  // same as Varibale declaration
  (public) test_class_var: int = 12;

  // constructor function
  (static, public) test_class: () {}
}

// Import library
// #import (name);
#import (io);

// Main function, entrypoint of app. NO access modifers
void main: () {}