#include <iostream>
#include <string>
#include <map>

using namespace std;

int romanToInt(string s){
    map<char, int> values{
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int result = 0;
    for(int i = 0; i < s.length(); i++){
        if(i + 1 < s.length() && values[s[i]] < values[s[i + 1]]){
            result += values[s[i + 1]] - values[s[i]];
            ++i;
        }
        else{
            result += values[s[i]];
        }
    }

    return result;
}

string intToRoman(int num){
    string result;
    pair<int, string> values[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, 
        {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    for(const auto& p : values){
        int weight = p.first;
        string symbol = p.second;

        while(num >= weight){
            result += symbol;
            num -= weight;
        }
    }

    return result;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    
    int arabian = romanToInt(s1) + romanToInt(s2);
    string roman = intToRoman(arabian);

    cout << arabian << endl;
    cout << roman << endl;

    return 0;
}