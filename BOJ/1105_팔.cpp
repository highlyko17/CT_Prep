#include <iostream>
#include <string>

using namespace std;

int main(){
    string L, R;
    int min = 0;

    cin >> L >> R;

    if(L.length() != R.length()){
        cout << 0;
    }
    else{
        for(int i = 0; i < L.size(); i++){
            if(L[i] != R[i]) break;
            if(L[i] == R[i] && L[i] == '8') min++;
        }

        cout << min;
    }

    return 0;
}