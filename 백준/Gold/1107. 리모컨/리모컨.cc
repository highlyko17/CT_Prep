#include <iostream>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    set<char> broken;
    for(int i = 0; i < M; i++) {
        char b;
        cin >> b;
        broken.insert(b);
    }

    int minPresses = abs(N - 100);

    for(int channel = 0; channel <= 999999; channel++) {
        string chStr = to_string(channel);
        bool possible = true;
        for(char c : chStr) {
            if(broken.count(c)) {
                possible = false;
                break;
            }
        }
        if(possible) {
            int presses = chStr.size() + abs(channel - N);
            minPresses = min(minPresses, presses);
        }
    }

    cout << minPresses << "\n";
    return 0;
}
