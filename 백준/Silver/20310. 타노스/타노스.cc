#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    string str;
    cin >> str;

    int zeros = 0, ones = 0;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == '0'){
            zeros++;
        }
        else ones++;
    }

    string new_str = "";
    for(int i = 0; i < zeros / 2; i++){
        new_str += '0';
    }
    for(int i = 0; i < ones / 2; i++){
        new_str += '1';
    }

    cout << new_str;

    return 0;
}