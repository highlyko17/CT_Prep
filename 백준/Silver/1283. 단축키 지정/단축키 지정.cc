#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

bool exist[26];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    cin.ignore(); 

    for(int i = 0; i < N; i++){
        string str;
        getline(cin, str);

        stringstream ss(str);
        string temp;
        vector<string> v;

        while(ss >> temp){
            v.push_back(temp);
        }

        int shortcut_pos = -1;
        int pos = 0;
        for(int j = 0; j < v.size(); j++){
            char c = v[j][0];
            char lower_c = tolower(c);

            if(!exist[lower_c - 'a']){
                exist[lower_c - 'a'] = true;
                shortcut_pos = pos;
                break;
            }
            pos += v[j].length() + 1;
        }

        if(shortcut_pos == -1){
            pos = 0;
            bool found = false;

            for(int j = 0; j < v.size() && !found; j++){
                for(int k = 0; k < v[j].length(); k++){
                    char c = v[j][k];
                    char lower_c = tolower(c);

                    if(!exist[lower_c - 'a']){
                        exist[lower_c - 'a'] = true;
                        shortcut_pos = pos + k;
                        found = true;
                        break;
                    }
                }
                if(!found) pos += v[j].length() + 1;
            }
        }

        for(int i = 0; i < str.length(); i++){
            if(i == shortcut_pos){
                cout << '[' << str[i] << ']';
            }
            else cout << str[i];
        }
        cout << '\n';
    }

    return 0;
}