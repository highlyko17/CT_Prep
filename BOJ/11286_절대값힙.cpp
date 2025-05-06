#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct cmp{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)) return a > b;
        else return abs(a) > abs(b);
    }
};

int main(){
    int N;
    cin >> N;

    priority_queue<int, vector<int>, cmp> q;
    vector<int> ans;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;

        if(temp == 0){
            if(q.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(q.top());
                q.pop();
            }
        }
        else q.push(temp);
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }

    return 0;
}