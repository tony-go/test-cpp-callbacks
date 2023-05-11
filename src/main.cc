#include <iostream>

#include "api.h"

int main() {
  std::cout << "Hello, World!" << std::endl;

  dummy_api("Hello", [](auto error) {
    if (error) {
      std::cout << "Error: " << *error << std::endl;
    } else {
      std::cout << "Success!" << std::endl;
    }
  });

  return 0;
}
