#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    string str;
    cin >> str;

    vector<bool> visited(str.length(), false);
    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'P') 
            visited[i] = true;
    }

    int answer = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'P'){
            for(int j = i - K; j <= i + K; j++){
                if(j < 0 || j >= N) continue;
                if(!visited[j]){
                    visited[j] = true;
                    answer++;
                    break;
                }


            }
        }
    }

    cout << answer;

    return 0;
}