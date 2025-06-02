#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp;

        string original = temp;

        if(next_permutation(temp.begin(), temp.end())){
            cout << temp << '\n';
        }
        else{
            cout << original << '\n';
        }
        
    }

    return 0;
}