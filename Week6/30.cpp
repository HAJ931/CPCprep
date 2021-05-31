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

bool checkIsomorphism(Node* root1, Node* root2){
    if(!root1 && !root2)
        return true;
    if(!root1 || !root2)
        return false;
    queue<Node*> q1, q2;
    vector<int> v;
    map<int, int> hMap;
    q1.push(root1);
    q2.push(root2);
    while(!q1.empty() && !q2.empty()){
        if(q1.size() != q2.size())
            return false;
        int count = q1.size();
        hMap.clear();
        v.clear();
        while(count--){
            Node *temp1 = q1.front();
            Node *temp2 = q2.front();
            q1.pop();
            q2.pop();
            if(hMap.find(temp1->data) == hMap.end())
                hMap[temp1->data] = 1;
            else
                hMap[temp1->data]++;
            if(temp1->left)
                q1.push(temp1->left);
            if(temp1->right)
                q1.push(temp1->right);
            if(temp2->left)
                q2.push(temp2->left);
            if(temp2->right)
                q2.push(temp2->right);
            v.push_back(temp2->data);
        }
        for(auto i: v){
            if(hMap.find(i) == hMap.end() || hMap[i] < 0)
                return false;
            else
                hMap[i]--;
            if(hMap[i] == 0)
                hMap.erase(i);
        }
        if(hMap.size() != 0)
            return false;
    }
    return true;
}

int main() {
	Node* n1 = new Node(1);
    n1->left = new Node(2);
    n1->right = new Node(3);
    n1->left->left = new Node(4);
    n1->left->right = new Node(5);
    n1->right->left = new Node(6);
    n1->left->right->left = new Node(7);
    n1->left->right->right = new Node(8);
 
    Node* n2 = new Node(1);
    n2->left = new Node(3);
    n2->right = new Node(2);
    n2->right->left = new Node(4);
    n2->right->right = new Node(5);
    n2->left->right = new Node(6);
    n2->right->right->left = new Node(8);
    n2->right->right->right = new Node(7);
 
    if (checkIsomorphism(n1, n2))
        cout << "Yes";
    else
        cout << "No";

}
