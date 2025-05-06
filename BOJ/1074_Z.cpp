#include <iostream>
#include <cmath>

using namespace std;

int N, r, c;
int answer = 0;

void dc(int x, int y, int size){
    if(x == c && y == r){
        cout << answer;
        return;
    }

    if(x <= c && y <= r && c < x + size && r < y + size){
        dc(x, y, size / 2); 
        dc(x + size / 2, y, size / 2);
        dc(x, y + size / 2, size / 2); 
        dc(x + size / 2, y + size / 2, size / 2); 
    }
    else{
        answer += size * size;
    }

}

int main(){
    cin >> N >> r >> c;

    dc(0, 0, pow(2, N));

    return 0;
}