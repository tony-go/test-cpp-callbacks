#include "api.h"

void dummy_api(const std::string &input, Callback callback) {
  if (input.empty()) {
    callback("Input string is empty.");
  } else {
    callback(std::nullopt);
  }
}
