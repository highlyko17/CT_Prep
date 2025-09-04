#include <iostream>
#include <vector>
#include <string>
using namespace std;

int calculateCommon(const string &a, const string &b) {
    int lim = min(a.size(), b.size());
    int cnt = 0;
    for (int i = 0; i < lim; i++) {
        if (a[i] == b[i]) cnt++;
        else break;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> words(N);

    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    int max_len = -1;
    pair<int,int> max_pair = {-1, -1};

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int len = calculateCommon(words[i], words[j]);
            
            if (len > max_len) {
                max_len = len;
                max_pair = {i, j};
            }
            else if (len == max_len) {
                if (i < max_pair.first || 
                    (i == max_pair.first && j < max_pair.second)) {
                    max_pair = {i, j};
                }
            }
        }
    }

    cout << words[max_pair.first] << "\n" << words[max_pair.second] << "\n";
    return 0;
}