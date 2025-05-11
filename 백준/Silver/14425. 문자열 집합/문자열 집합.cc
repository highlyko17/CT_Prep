#include <iostream>
#include <map>

using namespace std;

int N, M;
map<string, bool> m;
string str;
int cnt = 0;

int main(){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> str;
        m.insert({str, true});
    }

    for(int i = 0; i < M; i++){
        cin >> str;
        if(m[str] == true) cnt++;
    }

    cout << cnt;
    return 0;
}