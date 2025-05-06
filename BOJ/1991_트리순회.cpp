#include <iostream>
#include <map>

using namespace std;

int N;

struct Node{
    char left;
    char right;
};

map<char, Node> m;

void preOrder(char node){
    if(node == '.') return;

    cout << node;
    preOrder(m[node].left);
    preOrder(m[node].right);
}

void inOrder(char node){
    if(node == '.') return;

    inOrder(m[node].left);
    cout << node;
    inOrder(m[node].right);
}

void postOrder(char node){
    if(node == '.') return;

    postOrder(m[node].left);
    postOrder(m[node].right);
    cout << node;
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        char a, b, c;
        cin >> a >> b >> c;

        m[a].left = b;
        m[a].right = c;
    }

    preOrder('A');
    cout << endl;

    inOrder('A');
    cout << endl;

    postOrder('A');

    return 0;
}