#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
    int N;
    cin >> N;

    map<string, int> in;
    vector<int> out(N);

    for(int i = 0; i < N; i++){
        string str;
        cin >> str;

        in[str] = i;
    }
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;

        out[i] = in[str];
    }

    int cnt = 0;
    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            if(out[i] > out[j]){
                cnt++;
                break;
            }
        }
    }

    cout << cnt;

    return 0;
}