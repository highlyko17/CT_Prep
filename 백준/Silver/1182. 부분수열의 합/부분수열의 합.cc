#include <iostream>
#include <vector>

using namespace std;

int N, S, cnt;
vector<int> nums;

void dfs(int idx, int sum){
    if(idx == N){
        if(sum == S){
            cnt++;
        }
        return;
    }

    dfs(idx + 1, sum + nums[idx]);

    dfs(idx + 1, sum);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;

    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;

        nums.push_back(temp);
    }
    
    dfs(0, 0);

    if(S == 0)
        cnt--;

    cout << cnt;

    return 0;
}