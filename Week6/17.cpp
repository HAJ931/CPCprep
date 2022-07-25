#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertBST(Node* root, int data) {
    if(!root)
        return new Node(data);
    if(root->val > data)
        root->left = insertBST(root->left, data);
    else
        root->right = insertBST(root->right, data);
    return root;
}

vector<vector<int>> levelOrder(Node* root) {
    queue<Node*> q;
    vector<vector<int>> levels;
    if(root)
        q.push(root);
    while(q.size()) {
        int sz = q.size();
        vector<int> currLevel(sz);
        for(int i = 0; i < sz; ++i) {
            Node* curr = q.front();
            q.pop();
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
            //cout << curr->val << " ";
            currLevel[i] = curr->val;
        }
        //cout << "| ";
        levels.push_back(currLevel);
    }
    //cout << endl;
    return levels;
}

void zigZagTraversal (vector<vector<int>> levels) {
    int top = 0, rightPtr = 0;
    int bottom = levels.size() - 1, leftPtr = 0;
    int isTop = true;
    while(top < bottom) {
        if(isTop) {
            if(rightPtr < 0){
                ++top;
                rightPtr = levels[top].size() - 1;
            }
            cout << levels[top][rightPtr--] << " ";
        }
        else {
            if(leftPtr >= levels[bottom].size() - 1){
                --bottom;
                leftPtr = 0;
            }
            cout << levels[bottom][leftPtr++] << " ";
        }
        isTop = !isTop;
    }
    while(leftPtr < rightPtr) {
        isTop ? cout << levels[top][rightPtr--]: cout << levels[bottom][leftPtr++];
        isTop = !isTop;
    }
}

int main() {
    Node* root = new Node(25);
    vector<int> nodes = {15, 50, 10, 22, 35, 70, 4, 12, 18, 24, 31, 44, 66, 90};
    for(int i = 0; i < nodes.size(); ++i) {
        insertBST(root, nodes[i]);
    }
    vector<vector<int>> levels = levelOrder(root);
    zigZagTraversal(levels);
}
