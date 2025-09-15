#include <iostream>
#include <vector>
using namespace std;

int parent[201];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int x;
            cin >> x;
            if (x == 1) unite(i, j);
        }
    }

    vector<int> plan(M);
    for (int i = 0; i < M; i++) {
        cin >> plan[i];
    }

    bool possible = true;
    for (int i = 1; i < M; i++) {
        if (find(plan[i]) != find(plan[0])) {
            possible = false;
            break;
        }
    }

    cout << (possible ? "YES" : "NO");
    return 0;
}
