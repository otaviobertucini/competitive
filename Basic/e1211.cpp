//https://www.urionlinejudge.com.br/judge/en/problems/view/1211

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrieNode{
public:
    char data;
    vector<TrieNode*> children;
    int size(){return children.size();};
};

void insertTrie(TrieNode* node, string number, int index, int* count){
    for(int i = 0; i < node->size(); i++){
        if(node->children.at(i)->data == number[index]){
            insertTrie(node->children.at(i), number, index+1, count);
            return;
        }
    }
    TrieNode* newTrie = new TrieNode;
    newTrie->data = number[index];
    node->children.push_back(newTrie);
    (*count)++;
    if(index < number.size()-1){
        insertTrie(newTrie, number, index+1, count);
    }
    return;
}

void printTrie(TrieNode* node, string res){
    if(node->size() == 0){
        res += node->data;
        cout << res << endl;
        return;
    }
    for(int i = 0; i < node->size(); i++){
        res += node->data;
        printTrie(node->children.at(i), res);
    }
    return;
}

int main() {
    int n, dig, count;
    string number;
    while(cin >> n){
        count = 0;
        TrieNode* root = new TrieNode;
        root->data = '*';
        cin >> number;
        dig = number.size();
        insertTrie(root, number, 0, &count);
        for(int i = 0; i < n-1; i++){
            cin >> number;
            insertTrie(root, number, 0, &count);
        }

        cout << dig*n - count << endl;
    }
}
