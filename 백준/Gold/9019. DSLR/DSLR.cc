#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T;

int D(int n) { return (n * 2) % 10000; }
int S(int n) { return (n == 0 ? 9999 : n - 1); }
int L(int n) { return (n % 1000) * 10 + n / 1000; }
int R(int n) { return (n / 10) + (n % 10) * 1000; }

int main(){
    cin >> T;
    
    for(int i = 0; i < T; i++){
        int A, B;
        cin >> A >> B;

        vector<bool> visited(10000, false);
        vector<string> path(10000);
        queue<int> q;
        
        q.push(A);
        visited[A] = true;
        path[A] = "";

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(curr == B){
                cout << path[curr] << '\n';
                break;
            }

            int nxt;

            nxt = D(curr);
            if(!visited[nxt]){
                visited[nxt] = true;
                path[nxt] = path[curr] + "D";
                q.push(nxt);
            }

            nxt = S(curr);
            if(!visited[nxt]){
                visited[nxt] = true;
                path[nxt] = path[curr] + "S";
                q.push(nxt);
            }

            nxt = L(curr);
            if(!visited[nxt]){
                visited[nxt] = true;
                path[nxt] = path[curr] + "L";
                q.push(nxt);
            }

            nxt = R(curr);
            if(!visited[nxt]){
                visited[nxt] = true;
                path[nxt] = path[curr] + "R";
                q.push(nxt);
            }

        }
    }

    return 0;
}