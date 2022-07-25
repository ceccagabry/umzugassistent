#include "header/RuleMatcher.hpp"
#include <regex>

RuleMatcher::RuleMatcher():strBegin(""), strEnd(""), strSeparator(""), strRegExp("")
{
}

RuleMatcher RuleMatcher::beginWith(std::string begin)
{
    strBegin = begin;
    return *this;
}

RuleMatcher RuleMatcher::endWith(std::string end)
{
    strEnd = end;
    return *this;
}

RuleMatcher RuleMatcher::separator(std::string separator)
{
    strSeparator = separator;
    return *this;
}

RuleMatcher RuleMatcher::regExp(std::string regExp)
{
    strRegExp = regExp;
    return *this;
}

bool RuleMatcher::checkRule(std::string path)
{
    if(path.empty()){
        return false;
    }
    cout << "[RuleMatcher] path: " << path << endl;
    // get filename

    std::string filename = path.substr(path.find_last_of("/\\") + 1);
    cout << "[RuleMatcher] filename: " << filename << endl;

    cout << "[RuleMatcher] filename_beg: " << filename.substr(0,strBegin.size()) << endl;
    cout << "[RuleMatcher] filename_end: " << filename.substr(filename.size()- strEnd.size(), strEnd.size()) << endl;
    string fileName_mid = ""; 
    
    int offsetSize = strBegin.size() + strEnd.size();
    if(filename.size() - offsetSize > 0)
        fileName_mid = filename.substr(strBegin.size(),(filename.size() - offsetSize));    
    cout << "[RuleMatcher] fileName_mid: " << fileName_mid << endl;
    
    if(filename.substr(0,strBegin.size()) == strBegin && filename.substr(filename.size() - strEnd.size(), strEnd.size()) == strEnd) {
        
        size_t pos = 0;
        std::string token;
        bool isAHexToken;


        if(fileName_mid.size() > 0 && fileName_mid.find(strSeparator) == std::string::npos) {
            if (checkRegExp(fileName_mid)) {
                cout << "[RuleMatcher] file name is matching" << endl;
                return true;
            }
        }

        while ((pos = fileName_mid.find(strSeparator)) != std::string::npos) {
            token = fileName_mid.substr(0, pos);
            std::cout << "[RuleMatcher] Token: "<<token << std::endl;
            if (checkRegExp(token)) {
                cout << "[RuleMatcher] file name is matching" << endl;
                return true;
            }
                
            fileName_mid.erase(0, pos + strSeparator.length());
        }
    }
    cout << "[RuleMatcher] file name is NOT matching" << endl;
        return false;
}

bool RuleMatcher::checkRegExp (std::string name) {
    cout << "[RuleMatcher] Name(token):" << name << endl;
    bool match = false;
    try{
        auto mRegex = regex(strRegExp);
        match = regex_match (name, mRegex);
    }
    catch (const std::regex_error& e){
        return false;
    }
    return match;
}

RuleMatcher BuildRuleMatcher()
{
    return RuleMatcher();
}