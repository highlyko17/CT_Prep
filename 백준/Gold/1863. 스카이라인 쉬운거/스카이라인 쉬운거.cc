#include <iostream>
#include <stack>

using namespace std;

int n;

int main(){
    cin >> n;

    stack<int> st;
    int ans = 0;
    for(int i = 0; i <= n; i++){
        int x, y;
        if(i != n) cin >> x >> y;
        else y = 0;

        while(!st.empty() && st.top() >= y){
            if(st.top() != y) ans++;
            st.pop();
        }

        st.push(y);
    }

    cout << ans;
    return 0;
}