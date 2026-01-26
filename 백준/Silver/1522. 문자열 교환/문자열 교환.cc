#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str;
    cin >> str;

    int len = str.length();

    int a_cnt = 0;
    for(int i = 0; i < len; i++){
        if(str[i] == 'a') a_cnt++;
    }

    if(a_cnt == 0 || a_cnt == len){
        cout << 0;
        return 0;
    }

    str = str + str;

    int min_b = len;

    for(int i = 0; i < len; i++){
        int b_cnt = 0;

        for(int j = i; j < i+ a_cnt; j++){
            if(str[j] == 'b') b_cnt++;
        }

        min_b = min(min_b, b_cnt);
    }

    cout << min_b;

    return 0;
}