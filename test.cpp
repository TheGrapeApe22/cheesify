#include <bits/stdc++.h>

using namespace std;

int tokenCounter = 0;
unordered_map<string, string> tokens;

string generate(int n) {
    string base = "chee";

    // add e's to the base and adjust n by subtracting 64, 128, etc.
    int n2 = n;
    int multiplier = 64;
    while (1 << (base.size()+2) <= n2) {
        base += "e";
        n2 -= multiplier;
        multiplier *= 2;
    }
    base += "se";
    
    // bit manipulation
    string out = "";
    for (int i = 0; i < (int)base.size(); i++) {
        if ((n2 >> i) & 1)
            out += toupper(base[i]);
        else
            out += base[i];
    }
    return out;
}
string getCheese(string s) {
    if (tokens.find(s) != tokens.end())
        return tokens[s];
    string cheese = generate(tokenCounter);
    tokenCounter++;
}

int main() {
    auto print = [&](int n){
        cout << generate(n) << endl;
    };
    print(0);
    print(1);
    print(2);
    print(63);
    print(64);
    print(65);
    print(63+127);
    print(63+128);
    print(63+129);
    print(63+130);
}
