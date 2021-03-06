// Worst solution

#include <vector>
#include <iostream>
#include "Node.h"

using namespace std;

bool isBST(Node*);
void isBSTHelper(Node*, vector<int>&);
bool isInOrder(vector<int>&);

int main() {

    Node* n1 = new Node(4, nullptr, nullptr); 
    Node* n2 = new Node(6, nullptr, nullptr); 
    Node* n3 = new Node(6, nullptr, nullptr); 
    Node* n4 = new Node(10, nullptr, nullptr); 
    Node* n5 = new Node(5, n1, n2); 
    Node* n6 = new Node(9, n3, n4); 
    Node* root = new Node(7, n5, n6);
    cout << isBST(root) << endl;
    return 0;
}

bool isBST(Node* node) {
    vector<int> traversal;
    isBSTHelper(node, traversal);
    return isInOrder(traversal);    
}

void isBSTHelper(Node* node, vector<int>& traversal) {
    if (node == nullptr) return;
    isBSTHelper(node->left, traversal);
    traversal.push_back(node->data);
    isBSTHelper(node->right, traversal);
}

bool isInOrder(vector<int>& traversal) {
    for (int i = 0; i < traversal.size(); ++i) {
        cout << traversal[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < traversal.size() - 1; ++i) {
        if (traversal[i] > traversal[i + 1]) return false;
    }
    return true;
}


