#include <bits/stdc++.h>
#define ln "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
namespace {
    template<typename it> void print(it, it);
    template<typename T> void print(T& v) {print(all(v));}
    template<typename T, typename U> void print(pair<T, U> p) { cout << "("<<p.first<<", "<<p.second<<")"; }
    template<typename T, typename U>ostream& operator<<(ostream& out, pair<T, U> p) { print(p); return out; }
    template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) { print(v); return out; }
    template<typename T> ostream& operator<<(ostream& out, const set<T>& v) { print(v); return out; }
    template<typename T> ostream& operator<<(ostream& out, const multiset<T>& v) { print(v); return out; }
    template<typename T, typename U> ostream& operator<<(ostream& out, const map<T, U>& v) { print(v); return out; }
    template<typename it> void print(it begin, it end) {
        cout << "[";
        if (begin != end) {
            auto last = --end;
            for (; begin != last; begin++)
                cout << *begin << ", ";
            cout << *last;
        }
        cout << "]";
    }
    template<typename T> void println(T v) {print(v); cout << "\n";}
}

#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;


string readFile(const string& path) {
    ifstream file(path);
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

vector<string> split(string text, string delimiter) {
    regex re(delimiter);
    vector<string> tokens;
    sregex_iterator it(text.begin(), text.end(), re);
    sregex_iterator end;
    size_t pos = 0;

    for (; it != end; ++it) {
        if (static_cast<size_t>(it->position()) > pos)
            tokens.push_back(text.substr(pos, it->position() - pos));
        tokens.push_back(it->str());
        pos = it->position() + it->length();
    }
    if (pos < text.size())
        tokens.push_back(text.substr(pos));
    return tokens;
}

int main() {
    ofstream out("out2.txt");
    if (!out.is_open()) {
        cerr << "error, could not open file" << endl;
        return 1;
    }

    // parse with regex
    string text = readFile("victim.c");
    
    vector<string> tokens = split(text, R"((\n+|\s+|\w+))");

    out.close();
}
