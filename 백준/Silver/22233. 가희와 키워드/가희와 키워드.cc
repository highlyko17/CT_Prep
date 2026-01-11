#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    unordered_set<string> keyword;
    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp;

        keyword.insert(temp);
    }

    for(int i = 0; i < M; i++){
        string input;
        cin >> input;

        string curr = input;
        string word = "";
        for(int j = 0; j < curr.length(); j++){
            if(curr[j] == ','){
                //찾기
                if(keyword.count(word)){
                    --N;
                    keyword.erase(word);
                }
                word = "";
            }
            else{
                word += curr[j];
            }

            if(j == curr.length() - 1 && keyword.count(word)){
                --N;
                keyword.erase(word);
            }
        }

        cout << N << '\n';
    }

    return 0;
}