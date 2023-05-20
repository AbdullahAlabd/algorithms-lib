#include <vector>
#include <iostream>

using namespace std;

vector<int> LPS(const string& pattern) { // longest propper prefix that is a suffix
    vector<int> lps(pattern.length(), 0);
    int len = 0;
    for (int i = 1; i < pattern.length(); i++) {
        while (len && pattern[i] != pattern[len]) { // matching failure
            len = lps[len - 1];
        }
        if (pattern[len] == pattern[i]) {
            ++len;
        }
        lps[i] = len;
    }
    return lps;
}

void KMP(const string& text, const string& pattern) { // similar to the LPS except: matching is between pattern and text, and loop start at 0
    vector<int> lps = LPS(pattern);
    int len = 0;
    for (int i = 0; i < text.length(); i++) { // iterate over text, start at i = 0
        while (len && pattern[len] != text[i]) { // matching failure
            len = lps[len - 1];
        }
        if (pattern[len] == text[i]) {
            ++len;
        }
        if (len == pattern.length()) { // a match found;
            cout << "match at: " << i - pattern.length() + 1 << endl;
            len = lps[len - 1]; // fail intentionaly to find next match
        }
    }
}

int main() {
    string s, p;
    s = "abxababaaba"; // 0 0 0 1 2 1 2 1 1 2 1
    p = "aba"; // 0 0 1
    KMP(s, p);
}
