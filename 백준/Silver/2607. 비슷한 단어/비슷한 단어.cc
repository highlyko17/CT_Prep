#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    int N, answer = 0;
    cin >> N;

    string og;
    cin >> og;

    vector<int> og_vec(26, 0);
    for(char c : og){ 
        og_vec[c - 'A']++;
    }

    for(int i = 0; i < N - 1; i++){
        string str;
        cin >> str;

        if(abs((int)og.length() - (int)str.length()) >= 2) continue;

        vector<int> vec(26, 0);
        for(char c : str){ 
            vec[c - 'A']++;
        }

        int diff = 0;
        for(int i = 0; i < 26; i++){
            diff += abs(vec[i] - og_vec[i]);
        }

        if(diff <= 2) answer++;
    }

    cout << answer;

    return 0;
}