#include <future>

#include <gtest/gtest.h>

#include "../src/api.h"

TEST(dummy_api, return_error_on_empty_string) {
  std::promise<bool> waitGuard;
  const std::string empty_string = "";

  dummy_api(empty_string, [&waitGuard](MaybeError maybe_err) {
    EXPECT_EQ(maybe_err.value(), "Input string is empty.");
    waitGuard.set_value(true);
  });

  EXPECT_TRUE(waitGuard.get_future().get());
}

TEST(dummy_api, return_nullopt_on_non_empty_string) {
  std::promise<bool> waitGuard;
  const std::string non_empty_string = "non-empty";

  dummy_api(non_empty_string, [&waitGuard](MaybeError maybe_err) {
    EXPECT_EQ(maybe_err, std::nullopt);
    waitGuard.set_value(true);
  });

  EXPECT_TRUE(waitGuard.get_future().get());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
