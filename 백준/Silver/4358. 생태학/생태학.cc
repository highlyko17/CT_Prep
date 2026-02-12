#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> tree;
    string name;
    int total = 0;

    while (getline(cin, name)) {
        tree[name]++;
        total++;
    }

    cout << fixed;
    cout.precision(4);

    for (auto &p : tree) {
        double percent = (double)p.second / total * 100;
        cout << p.first << " " << percent << "\n";
    }

    return 0;
}
