#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    string s;
    cin >> s;

    int rFirst = 0, rLast = 0;
    
    int idx = 0;
    while(s[idx] == 'R') idx++;

    for(int i = idx; i < N; i++){
        if(s[i] == 'R') rFirst++;
    }

    idx = N - 1;
    while(s[idx] == 'R') idx--;

    for(int i = idx; i >= 0; i--){
        if(s[i] == 'R') rLast++;
    }

    int rMin = min(rFirst, rLast);

    int bFirst = 0, bLast = 0;
    
    idx = 0;
    while(s[idx] == 'B') idx++;

    for(int i = idx; i < N; i++){
        if(s[i] == 'B') bFirst++;
    }

    idx = N - 1;
    while(s[idx] == 'B') idx--;

    for(int i = idx; i >= 0; i--){
        if(s[i] == 'B') bLast++;
    }

    int bMin = min(bFirst, bLast);

    int answer = min(rMin, bMin);
    cout << answer;

    return 0;
}