#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;
std::vector<std::string> findAll(const std::string& text, const std::string& pattern) {
    std::vector<std::string> matches;
    std::regex re(pattern);
    std::sregex_iterator begin(text.begin(), text.end(), re);
    std::sregex_iterator end;

    for (auto it = begin; it != end; ++it) {
        matches.push_back(it->str());
    }

    return matches;
}

int main() {
    std::string text = "-//-";
    std::string pattern = R"((//|/\*|\*/|"| +|\n+|\w+|[^ \w\n]+))"; // matches the word "in"

    std::vector<std::string> result = findAll(text, pattern);

    for (const auto& match : result) {
        std::cout << "'" << match << "'\n";
    }

    return 0;
}
