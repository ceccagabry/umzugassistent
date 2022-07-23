#pragma once

#include <iostream>
#include <fstream>
#include <cstdint>

using namespace std;

class RuleMatcher {
  public:
    RuleMatcher();
    RuleMatcher beginWith(std::string begin);
    RuleMatcher endWith(std::string end);
    RuleMatcher separator(std::string separator);
    RuleMatcher regExp(std::string name);
    bool checkRule(std::string path);

  private:
    bool checkRegExp (std::string name);
    std::string strBegin;
    std::string strEnd;
    std::string strSeparator;
    std::string strRegExp;

    };

RuleMatcher BuildRuleMatcher();