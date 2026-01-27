#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    int temp;
    for(int i = 0; i < N; i++){
        cin >> temp;

        if(temp == 0){
            if(!pq.empty()){
                cout << pq.top() << '\n';
                pq.pop();
            }
            else cout << 0 << '\n';
        }
        else{
            pq.push(temp);
        }
    }

    return 0;
}