#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> sum(M, vector<int>(4, 0));
    vector<string> original;
    // 0 = A, 1 = C, 2 = G, 3 = T

    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        original.push_back(str);
        for(int j = 0; j < M; j++){
            if(str[j] == 'A') sum[j][0]++;
            else if(str[j] == 'C') sum[j][1]++;
            else if(str[j] == 'G') sum[j][2]++;
            else if (str[j] == 'T') sum[j][3]++;
        }
    }

    string answer = "";
    for(int i = 0; i < M; i++){
        int max_idx = 0, max = sum[i][0];
        for(int j = 1; j < 4; j++){
            if(max < sum[i][j]){
                max_idx = j;
                max = sum[i][j];
            }
        }
        if(max_idx == 0) answer += 'A';
        else if(max_idx == 1) answer += 'C';
        else if(max_idx == 2) answer += 'G';
        else if(max_idx == 3) answer += 'T';
    }
    
    int hd = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(original[i][j] != answer[j]) hd++;
        }
    }

    cout << answer << '\n' << hd;

    return 0;
}