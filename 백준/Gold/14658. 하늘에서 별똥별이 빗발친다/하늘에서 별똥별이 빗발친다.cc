#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, L, K;

int main(){
    cin >> N >> M >> L >> K;

    vector<pair<int, int> > meteor(K);
    for(int i = 0; i < K; i++){
        int x, y;
        cin >> x >> y;

        meteor[i] = {x, y};
    }

    int answer = 0;
    for(int i = 0; i < K; i++){
        for(int j = 0; j < K; j++){
            int startx = meteor[i].first;
            int starty = meteor[j].second;

            int cnt = 0;
            for(int k = 0; k < K; k++){
                int x = meteor[k].first;
                int y = meteor[k].second;

                if(startx <= x && x <= startx + L
                    && starty <= y && y <= starty + L){
                        cnt++;
                    }
            }

            answer = max(answer, cnt);
        }
    }

    cout << K - answer;

    return 0;
}