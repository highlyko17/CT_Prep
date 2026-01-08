#include <iostream>
#include <string>

using namespace std;

bool doesMatch(string seq, string s){
    int idx = 0;

    for(int i = 0; i < seq.length() && idx < s.length(); i++){
        if(seq[i] == s[idx]){
            idx++;
        }
    }

    return idx == s.length();
}

int main(){
    string s;
    cin >> s;

    int maxN = s.length() * 10;
    string seq = "";

    for(int n = 1; n <= maxN; n++){
        seq += to_string(n);
        if(doesMatch(seq, s)){
            cout << n;
            break;
        }
    }

    return 0;
}