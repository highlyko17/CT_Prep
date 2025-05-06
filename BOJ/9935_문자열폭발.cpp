#include <iostream>
#include <string>

using namespace std;

int main(){
    string str, bomb, result;
    cin >> str >> bomb;

    int bomb_len = bomb.size();

    for(char c : str){
        result.push_back(c);

        if(result.size() >= bomb_len && c == bomb[bomb_len - 1]){
            if(result.substr(result.size() - bomb_len)  == bomb){
                result.erase(result.size() - bomb_len);
            }
        }
    }

    if(result.size() == 0){
        cout << "FRULA";
    }
    else cout << result;
    return 0;
}