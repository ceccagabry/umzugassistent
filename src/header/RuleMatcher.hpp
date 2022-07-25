#pragma once

#include <iostream>
#include <fstream>
#include <cstdint>

using namespace std;

/**
 * @brief Class that check if a file name is matching the passed rules 
 * 
 */
class RuleMatcher {
  public:

    /**
     * @brief Construct a new Rule Matcher object
     * 
     */
    RuleMatcher();

    /**
     * @brief set the begin of the file name
     * 
     * @param begin - string that represent the beginning of the file name
     * @return RuleMatcher 
     */
    RuleMatcher beginWith(std::string begin);

    /**
     * @brief set the end of a file name
     * 
     * @param end - string that represent the end of the file name
     * @return RuleMatcher 
     */
    RuleMatcher endWith(std::string end);

    /**
     * @brief set the separator to check in the file name
     * 
     * @param separator - string that represent the separator to consider in the file name
     * @return RuleMatcher 
     */
    RuleMatcher separator(std::string separator);

    /**
     * @brief set the regolar expression 
     * 
     * @param name - - string that represent the regular expression to check in the file name
     * @return RuleMatcher 
     */
    RuleMatcher regExp(std::string name);

    /**
     * @brief Method that checks if the name passed is conform to the rules
     * 
     * @param path - path that contains the file name 
     * @return true - all rules are respected
     * @return false - not all rules are respected
     */
    bool checkRule(std::string path);

  private:

    /**
     * @brief method that checks if the name respect the regular expression
     * 
     * @param name 
     * @return true - the name respect the regular expression
     * @return false - the name doesn't respect the regular expression
     */
    bool checkRegExp (std::string name);

    std::string strBegin;
    std::string strEnd;
    std::string strSeparator;
    std::string strRegExp;

    };

RuleMatcher BuildRuleMatcher();