#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<int> towers;

int main(){
    int N;
    cin >> N;

    vector<int> towers(N), answer(N, 0);

    for(int i = 0; i < N; i++){
        cin >> towers[i];
    }

    stack<pair<int, int>> st;
    for(int i = 0; i < N; i++){
        while(!st.empty() && st.top().second < towers[i]){
            st.pop();
        }
        if(!st.empty()) answer[i] = st.top().first + 1;
        st.push({i, towers[i]});
    }

    for(int i = 0; i < N; i++){
        cout << answer[i] << ' ';
    }

    return 0;
}