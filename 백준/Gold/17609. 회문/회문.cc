#include <iostream>
#include <string>

using namespace std;

int isPalindrome(string str, int left, int right, int del){
    while(left < right){
        if(str[left] == str[right]){
            left++;
            right--;
        }
        else{
            if(del == 0){
                if(isPalindrome(str, left + 1, right, 1) == 0 || isPalindrome(str, left, right - 1, 1) == 0){
                    return 1;
                }
                else return 2;
            }
            else return 2;
        }
    }

    return 0;
}

int main(){
    int num;
    cin >> num;

    for(int i = 0; i < num; i++){
        string str;
        cin >> str;

        int result = isPalindrome(str, 0, str.length() - 1, 0);
        cout << result << '\n';;
    }

    return 0;
}