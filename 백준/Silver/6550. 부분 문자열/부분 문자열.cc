#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, t;
    while (cin >> s >> t) {
        int s_idx = 0, t_idx = 0;

        while (s_idx < s.length() && t_idx < t.length()) {
            if (s[s_idx] == t[t_idx]) {
                ++s_idx;
            }
            ++t_idx;
        }

        if (s_idx == s.length()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
