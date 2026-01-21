#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int T;
    cin >> T;
    cin.ignore();

    while(T--){
        string recordLine;
        getline(cin, recordLine);

        vector<string> sounds;
        stringstream ss(recordLine);
        string word;
        while(ss >> word){
            sounds.push_back(word);
        }

        set<string> animalSounds;
        string str;

        while(getline(cin, str)){
            if(str.find("what does the fox say?") != string::npos){
                break;
            }

            stringstream sss(str);
            string animal, goes, sound;
            sss >> animal >> goes >> sound;

            if(goes == "goes"){
                animalSounds.insert(sound);
            }
        }

        bool first = true;
        for(auto s : sounds){
            if(animalSounds.find(s) == animalSounds.end()){
                if(!first) cout << ' ';
                cout << s;
                first = false;
            }

        }

        cout << '\n';
    }

    return 0;

}