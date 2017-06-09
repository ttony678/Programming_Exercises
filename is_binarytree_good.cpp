//Good solution

#include <vector>
#include <iostream>
#include <climits>
#include "Node.h"

using namespace std;

bool isBST(Node*);
bool isBSTHelper(Node*, int, int);
bool outOfBounds(int, int, int);

int main() {

    Node* n1 = new Node(4, nullptr, nullptr); 
    Node* n2 = new Node(6, nullptr, nullptr); 
    //Node* n2 = new Node(4, nullptr, nullptr); 
    //Node* n3 = new Node(6, nullptr, nullptr); 
    Node* n3 = new Node(8, nullptr, nullptr); 
    Node* n4 = new Node(10, nullptr, nullptr); 
    Node* n5 = new Node(5, n1, n2); 
    //Node* n5 = new Node(4, n1, n2); 
    Node* n6 = new Node(9, n3, n4); 
    Node* root = new Node(7, n5, n6);
    cout << isBST(root) << endl;
    return 0;
}

bool isBST(Node* node) {
    isBSTHelper(node, INT_MIN, INT_MAX);
}

bool isBSTHelper(Node* node, int min, int max) {
    if (node == nullptr) return true;
    if (outOfBounds(node->data, min, max)) return false;
    return (isBSTHelper(node->left, min, node->data) &&
            isBSTHelper(node->right, node->data, max));
}

bool outOfBounds(int data, int min, int max) {
    return (data > max) || (data <= min);
}
