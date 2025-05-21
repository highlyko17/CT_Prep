#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        int N;
        cin >> N;

        string input, target;
        cin >> input;
        cin >> target;

        int b_to_w = 0, w_to_b = 0;

        for(int j = 0; j < N; j++){
            if(input[j] != target[j]){
                if(target[j] == 'B') w_to_b++;
                else b_to_w++;
            }
        }

        int swaps = min(b_to_w, w_to_b);
        int flips = abs(b_to_w - w_to_b);

        cout << swaps + flips << '\n';
    }

    return 0;
}