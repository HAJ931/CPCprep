#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    private:
    bool DFS(int i, vector<int> adj[], vector<bool>& vis, vector<bool>& recStack){
        vis[i] = true;
        recStack[i] = true;
        for(auto x: adj[i]){
            if(!vis[x] && DFS(x, adj, vis, recStack))
                return true;
            else if (recStack[x])
                return true;
        }
        recStack[i] = false;
        return false;
    }
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	vector<bool> vis(V, false);
	   	vector<bool> recStack(V, false);
	   	for(int i = 0; i < V; ++i){
	   	    if(!vis[i]){
	   	        if(DFS(i, adj, vis, recStack))
	   	            return true;
	   	    }
	   	}
	   	return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
