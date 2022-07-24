//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
        class Node {
            public:
            char data;
            int freq;
            Node* left;
            Node* right;
            Node(char data, int freq) {
                this->data = data;
                this->freq = freq;
                this->left = NULL;
                this->right = NULL;
            }
            Node(int freq, Node* leftChild, Node* rightChild) {
                this->freq = freq;
                this->left = leftChild;
                this->right = rightChild;
            }
        };
        struct compareFunc {
            bool operator()(Node* Node1, Node* Node2){
                return Node1->freq > Node2->freq;
            }
        };
        Node* createHuffmanTree (string S, vector<int> f, int N) {
            priority_queue<Node*, vector<Node*>, compareFunc> huffmanQueue;
            for(int i = 0; i < N; ++i) {
                huffmanQueue.push(new Node(S[i], f[i]));
            }
            /*while(huffmanQueue.size()) {
                cout << huffmanQueue.top()->freq<< " ";
                huffmanQueue.pop();
            }
            cout << endl;
            return NULL;*/
            while(huffmanQueue.size() >= 2) {
                Node *leftChild = huffmanQueue.top();
                int leftFreq = leftChild->freq;
                huffmanQueue.pop();
                Node* rightChild = huffmanQueue.top();
                int rightFreq = rightChild->freq;
                huffmanQueue.pop();
                //cout << "adding " << leftFreq << " and " << rightFreq << endl;
                huffmanQueue.push(new Node(leftFreq + rightFreq, leftChild, rightChild));
            }
            return huffmanQueue.top();
        }
        void huffmanTraversal (Node* root, vector<string>& res, string s) {
            if(!root)
                return;
            if(!root->left && !root->right){
                res.push_back(s);
                return;
            }
            huffmanTraversal(root->left, res, s + "0");
            huffmanTraversal(root->right, res, s + "1");
        }
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    Node* root = createHuffmanTree(S, f, N);
		    string huffmanCode = "";
		    vector<string> res;
		    huffmanTraversal(root, res, huffmanCode);
		    return res;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends
