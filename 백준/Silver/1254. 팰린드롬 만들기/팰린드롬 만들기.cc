#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str){
    int left = 0;
    int right = str.length() - 1;

    while(left <= right){
        if(str[left] != str[right]) return false;
        left++;
        right--;
    }

    return true;
}

int main(){
    string str;
    cin >> str;

    int len = str.length();

    for(int i = 0; i < len; i++){
        if(isPalindrome(str.substr(i))){
            cout << len + i;
            return 0;
        }
    }

    return 0;
}