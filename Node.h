#ifndef _NODE_H
#define _NODE_H

struct Node {
    Node() : data(0), left(nullptr), right(nullptr) {};
    Node(int data, Node* left, Node* right) 
            : data(data), left(left), right(right) {};
    int data;
    Node* left;
    Node* right;
};

void insertNode(Node* root, int value) {
    if (root->left == nullptr && value < root->data) {
        root->left = new Node(value, nullptr, nullptr);
        return;
    }
    if (root->right == nullptr && value >= root->data) {
        root->right = new Node(value, nullptr, nullptr);
        return;
    }
    if (value < root->data) {
        insertNode(root->left, value);
    }
    else {
        insertNode(root->right, value);
    }
}

#endif
