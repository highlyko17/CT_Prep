#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr[3];
set<int> answer;
bool visited[201][201][201];

int main(){
    for(int i = 0; i < 3; i++){
        cin >> arr[i];
    }

    queue<vector<int>> q;
    q.push({0, 0, arr[2]});
    visited[0][0][arr[2]] = true;

    while(!q.empty()){
        vector<int> curr = q.front();
        q.pop();

        if(curr[0] == 0) answer.insert(curr[2]);

        for(int start = 0; start < 3; start++){
            for(int dest = 0; dest < 3; dest++){
                if(start == dest) continue;
                if(curr[start] == 0) continue;
                if(curr[dest] == arr[dest]) continue;

                vector<int> next = curr;

                int amount = min(next[start], arr[dest] - next[dest]);
                next[start] -= amount;
                next[dest] += amount;

                if(!visited[next[0]][next[1]][next[2]]){
                    visited[next[0]][next[1]][next[2]] = true;
                    q.push(next);
                }
            }
        }
    }

    for(int n : answer){
        cout << n << ' ';
    }

    return 0;
}