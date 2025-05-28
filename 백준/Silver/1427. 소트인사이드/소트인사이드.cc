#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    string str = to_string(N);

    sort(str.begin(), str.end(), greater<char>());

    cout << str;

    return 0;
}