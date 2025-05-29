#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string toJava(string str){
    string result = "";
    for(int i = 0; i < str.length(); i++){
        if(isupper(str[i])){
            return "Error!";
        }
        else if(str[i] == '_'){
            if(i + 1 >= str.length() || str[i + 1] == '_'){
                return "Error!";
            }
            result += toupper(str[i + 1]);
            i++;
        }
        else{
            result += str[i];
        }
    }

    return result;
}

string toCpp(string str) {
    string result = "";
    for (char c : str) {
        if (c == '_') return "Error!";
        if (isupper(c)) {
            result += '_';
            result += tolower(c);
        } else {
            result += c;
        }
    }
    return result;
}

bool isCpp(string str){
    if (str[0] == '_' || str[str.length() - 1] == '_') return false;
    for (int i = 0; i < str.length(); i++) {
        if (isupper(str[i])) return false;
        if (str[i] == '_' && str[i + 1] == '_') return false;
    }
    return str.find('_') != string::npos;
}

bool isJava(string str){
    if (!islower(str[0])) return false;
    for (char c : str) {
        if (c == '_') return false;
    }
    return true;
}

int main(){
    string str;
    cin >> str;

    string result;

    if(isCpp(str)){
        result = toJava(str);
    }
    else if(isJava(str)){
        result = toCpp(str);
    }
    else{
        result = "Error!";
    }

    cout << result;
    
    return 0;
}