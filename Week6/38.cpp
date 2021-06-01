#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x){
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

bool checkChildrenSum(Node* node){
    if(!node || (!node->left && !node->right))
        return true;
    int leftKey = 0, rightKey = 0;
    if(node->left)
        leftKey = node->left->data;
    if(node->right)
        rightKey = node->right->data;
    if(node->data == leftKey + rightKey && checkChildrenSum(node->left) && checkChildrenSum(node->right))
        return true;
    return false;
}

int main() {
	Node* n1 = new Node(10);
    n1->left = new Node(8);
    n1->right = new Node(2);
    n1->left->left = new Node(3);
    n1->left->right = new Node(5);
    n1->right->left = new Node(2);
 
    if (checkChildrenSum(n1))
        cout << "Yes";
    else
        cout << "No";

}
