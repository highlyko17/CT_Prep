#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int H, W;
    cin >> H >> W;

    vector<int> blocks(W);
    for(int i = 0; i < W; i++){
        cin >> blocks[i];
    }

    vector<int> leftMax(W), rightMax(W);

    leftMax[0] = blocks[0];
    for(int i = 1; i < W; i++){
        leftMax[i] = max(leftMax[i - 1], blocks[i]);
    }

    rightMax[W - 1] = blocks[W - 1];
    for(int i = W - 2; i >= 0; i--){
        rightMax[i] = max(rightMax[i + 1], blocks[i]);
    }

    int answer = 0;
    for(int i = 0; i < W; i++){
        int height = min(leftMax[i], rightMax[i]);
        if(height > blocks[i]) answer += height - blocks[i];
    }

    cout << answer;

    return 0;
}