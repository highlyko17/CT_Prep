#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    int T;
    cin >> T;

    while (T--) {
        string p, nums;
        int n;
        cin >> p >> n >> nums;

        deque<int> dq;
        string num = "";

        for (char c : nums) {
            if (isdigit(c)) {
                num += c;
            } else if (!num.empty()) {
                dq.push_back(stoi(num));
                num = "";
            }
        }

        bool reverseFlag = false;
        bool errorFlag = false;

        for (char cmd : p) {
            if (cmd == 'R') {
                reverseFlag = !reverseFlag;
            } 
            else if (cmd == 'D') {
                if (dq.empty()) {
                    errorFlag = true;
                    break;
                }
                if (reverseFlag) {
                    dq.pop_back();
                } else {
                    dq.pop_front();
                }
            }
        }

        // 결과 출력
        if (errorFlag) {
            cout << "error\n";
        } 
        else {
            cout << "[";
            if (!dq.empty()) {
                if (reverseFlag) {
                    for (auto it = dq.rbegin(); it != dq.rend(); ++it) {
                        if (it != dq.rbegin()) cout << ",";
                        cout << *it;
                    }
                } 
                else {
                    for (auto it = dq.begin(); it != dq.end(); ++it) {
                        if (it != dq.begin()) cout << ",";
                        cout << *it;
                    }
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}
