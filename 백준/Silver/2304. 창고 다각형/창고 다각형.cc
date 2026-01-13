#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<pair<int, int>> col;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;

        col.push_back({a, b});
    }

    sort(col.begin(), col.end());

    int max_height = 0, max_idx = 0;
    for(int i = 0; i < N; i++){
        if(col[i].second > max_height){
            max_height = col[i].second;
            max_idx = i;
        }
    }

    int curr_height = 0;
    int area = 0;
    for(int i = 0; i <= max_idx; i++){
        if(col[i].second > curr_height){
            curr_height = col[i].second;
        }

        if(i < max_idx){
            int width = col[i + 1].first - col[i].first;
            area += width * curr_height;
        }
        else{
            area += curr_height;
        }
    }

    curr_height = 0;
    for(int i = N - 1; i > max_idx; i--){
        if(col[i].second > curr_height){
            curr_height = col[i].second;
        }

        int width = col[i].first - col[i - 1].first;
        area += width * curr_height;
    }

    cout << area;

    return 0;
}