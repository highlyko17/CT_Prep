#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str;
    cin >> str;

    int len = str.length();
    string result = "";

    for(int i = 1; i < len - 1; i++){
        for(int j = i + 1; j < len; j++){
            string part1 = str.substr(0, i);
            string part2 = str.substr(i, j - i);
            string part3 = str.substr(j);

            reverse(part1.begin(), part1.end());
            reverse(part2.begin(), part2.end());
            reverse(part3.begin(), part3.end());

            string new_str = part1 + part2 + part3;

            if(result == "") result = new_str;
            else {
                if (new_str < result) result = new_str;
            }
        }
    }

    cout << result;

    return 0;
}