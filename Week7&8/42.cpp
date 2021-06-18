class Solution {
//true blue
//false red
#define pib pair<int, bool>
private:
    bool BFS(int s, set<int>& blue, set<int>& red, vector<bool>& vis, vector<vector<int>>& graph){
        queue <pib> q;
        q.push(make_pair(s, false));
        red.insert(s);
        vis[s] = true;
        while(!q.empty()){
            pib curr = q.front();
            q.pop();
            int v = curr.first;
            bool col = curr.second; 
            for(auto x: graph[curr.first]){
                //If the vertex in the adjacency list has been visited already
                if(vis[x]){
                    //If the current vertex is coloured red
                    if(!col){
                        //Then the adjacent vertex cannot be coloured red already
                        if(red.find(x) != red.end())
                            return false;
                    }
                    //Else the current vertex is coloured blue
                    //Then the adjacent vertex cannot be coloured blue
                    else if(blue.find(x) != blue.end())
                        return false;
                }
                else{
                    q.push(make_pair(x, !col));
                    //If colour of the current vertex is red
                    if(!col){
                        //Push the adjacent vertex into the blue set
                        blue.insert(x);
                    }
                    else red.insert(x);
                    q.push(make_pair(x, !col));
                    vis[x] = true;
                }       
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> vis (graph.size(), false);
        set<int> blue, red;
        for(int i = 0; i < graph.size(); ++i){
            if(!vis[i]){
                if(!BFS(i, blue, red, vis, graph))
                    return false;
            }
        }
        return true;
    }
};
