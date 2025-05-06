#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, int> > house, chicken;
vector<int> selected;
int minAnswer = 1e9;

void calculateDistance(){
    int distSum = 0;
    for(int i = 0; i < house.size(); i++){
        int hx = house[i].first; int hy = house[i].second;
        int minDist = 1e9;
        for(int j = 0; j < selected.size(); j++){
            int cx = chicken[selected[j]].first; int cy = chicken[selected[j]].second;
            minDist = min(minDist, abs(hx - cx) + abs(hy - cy));
        }
        distSum += minDist;
    }
    minAnswer = min(minAnswer, distSum);
}

void combi(int depth, int idx){
    if(depth == M){
        calculateDistance();
        return ;
    }

    for(int i = idx; i < chicken.size(); i++){
        selected.push_back(i);
        combi(depth + 1, i + 1);
        selected.pop_back();
    }
}

int main(){
    cin >> N >> M;
   
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int temp;
            cin >> temp;

            if(temp == 1) house.push_back({i, j});
            else if(temp == 2) chicken.push_back({i, j});
        }
    }

    combi(0, 0);
    cout << minAnswer;

    return 0;
}