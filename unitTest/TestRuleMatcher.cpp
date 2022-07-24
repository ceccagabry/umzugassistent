#include "header/RuleMatcher.hpp"
#include <gtest/gtest.h>



TEST(TestRuleMatcher, test_checkRule_true) {
    auto rm = BuildRuleMatcher().beginWith("core.").endWith("lz4").separator(".").regExp("[0-9a-fA-F]+");
    std::string path ("/tmp/core.a10a.lz4");
    ASSERT_EQ(rm.checkRule(path), true);
}

TEST(TestRuleMatcher, test_checkRule_false) {
    auto rm = BuildRuleMatcher().beginWith("core.").endWith("lz4").separator(".").regExp("[0-9a-fA-F]+");
    std::string path ("/tmp/core.pppp.lz4");
    ASSERT_EQ(rm.checkRule(path), false);
}

TEST(TestRuleMatcher, test_checkRule_specialCharsEnd) {
    auto rm = BuildRuleMatcher().beginWith("core.").endWith("!?$").separator(".").regExp("[0-9a-fA-F]+");
    std::string path ("/tmp/core.a10a.lz4");
    ASSERT_EQ(rm.checkRule(path), false);
}

TEST(TestRuleMatcher, test_checkRule_specialCharsPath) {
    auto rm = BuildRuleMatcher().beginWith("core.").endWith("!?$").separator(".").regExp("[0-9a-fA-F]+");
    std::string path ("/tmp/core.a1!%?&0a.lz4");
    ASSERT_EQ(rm.checkRule(path), false);
}

TEST(TestRuleMatcher, test_checkRule_emptyPath) {
    auto rm = BuildRuleMatcher().beginWith("core.").endWith("!?$").separator(".").regExp("[0-9a-fA-F]+");
    std::string path ("");
    ASSERT_EQ(rm.checkRule(path), false);
}
