#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string temp = "";

void ab(string S, string T){
    if(S == T){
        cout << 1;
        exit(0);
    }
    if(S.length() >= T.length()){
        return;
    }

    if(T[T.length() - 1] == 'A'){
        temp = T;
        temp.erase(temp.length() - 1);
        ab(S, temp);
    }

    if(T[0] == 'B'){
        temp = T;
        temp.erase(temp.begin());
        reverse(temp.begin(), temp.end());
        ab(S, temp);
    }
}

int main(){
    string S, T;
    cin >> S;
    cin >> T;

    ab(S, T);
    cout << 0;

    return 0;
}