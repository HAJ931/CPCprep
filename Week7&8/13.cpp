class Solution {
private:
    int dfs(vector<vector<int>>& adjList, vector<int>& ans, vector<int>& quiet, int i){
        if(ans[i] == -1) {
            ans[i] = i;
            for(auto x: adjList[i]){
                int newMin = dfs(adjList, ans ,quiet, x);
                if(quiet[newMin] < quiet[ans[i]])
                    ans[i] = newMin;
            }
        }
        return ans[i];
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<vector<int>> adjList(quiet.size());
        for(auto x: richer) {
            adjList[x[1]].push_back(x[0]);
        }
        vector<int> ans(quiet.size(), -1);
        for(int i = 0; i < adjList.size(); ++i){
            dfs(adjList, ans, quiet, i);
        }
        return ans;
    }
};
