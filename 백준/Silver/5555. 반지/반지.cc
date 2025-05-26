#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string search;
    cin >> search;

    int ring_num, answer = 0;
    cin >> ring_num;

    string ring;
    for(int i = 0; i < ring_num; i++){
        cin >> ring;

        for(int i = 0; i < search.length() - 1; i++){
            ring.push_back(ring[i]);
        }

        if(ring.find(search) != string::npos){
            answer++;
        }
    }

    cout << answer;

    return 0;
}