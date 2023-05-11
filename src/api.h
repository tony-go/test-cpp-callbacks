#include <functional>
#include <optional>
#include <string>

using MaybeError = std::optional<std::string>;
using Callback = std::function<void(MaybeError)>;

void dummy_api(const std::string &input, Callback callback);
