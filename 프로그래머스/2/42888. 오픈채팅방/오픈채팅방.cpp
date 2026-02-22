#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> nickname;
    
    for(string r: record){
        string command, uid, name;
        stringstream ss(r);
        
        ss >> command >> uid;
        
        if(command == "Enter" || command == "Change"){
            ss >> name;
            nickname[uid] = name;
        }
    }
    
    for(string r: record){
        string command, uid, name;
        stringstream ss(r);
        ss >> command >> uid;
        
        if(command == "Enter"){
            answer.push_back(nickname[uid] + "님이 들어왔습니다.");
        }
        else if(command == "Leave"){
            answer.push_back(nickname[uid] + "님이 나갔습니다.");
        }
    }
    
    return answer;
}