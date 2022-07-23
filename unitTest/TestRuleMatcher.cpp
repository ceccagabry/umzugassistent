#include "header/RuleMatcher.hpp"
#include <gtest/gtest.h>

auto rm = BuildRuleMatcher().beginWith("core.").endWith("lz4").separator(".").regExp("[0-9a-fA-F]+");


TEST(TestRuleMatcher, test_checkRule) {
   std::string path ("/tmp/core.a10a.lz4");
    ASSERT_EQ(rm.checkRule(path), true);
}

TEST(TestRuleMatcher, test_checkRuleNot) {
    std::string path ("/tmp/core.pppp.lz4");
    ASSERT_EQ(rm.checkRule(path), false);
}
