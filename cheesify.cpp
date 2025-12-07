#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

vector<string> split_by_regex(const string& text, const string& regex_pattern) {
    regex rgx(regex_pattern);
    sregex_token_iterator iter(text.begin(), text.end(), rgx, -1);
    sregex_token_iterator end;

    vector<string> tokens;
    for (; iter != end; ++iter) {
        if (!iter->str().empty())
            tokens.push_back(*iter);
    }
    return tokens;
}
