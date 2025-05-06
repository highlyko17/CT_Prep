#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    a = "0" + a;
    b = "0" + b;

    vector<vector<int> > lcs(a.length(), vector<int>(b.length(), 0));
    for(int i = 0; i < a.length(); i++){
        for(int j = 0; j < b.length(); j++){
            if(i == 0 || j == 0) lcs[i][j] = 0;
            else if(a[i] == b[j]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else{
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }

    cout << lcs[a.length() - 1][b.length() - 1];
}