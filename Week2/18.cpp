#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
public:     
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int indicator[r][c];
        vector<int> ans;
        char direction = 'R';
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                indicator[i][j] = 0;
            }
        }
        int i = 0, j = 0, count = 0;
        while(count < r * c){
            switch(direction){
                case 'R':
                    while(j < c){
                        if(indicator[i][j] == 1)
                            break;
                        ans.push_back(matrix[i][j]);
                        indicator[i][j] = 1;
                        ++j;
                        ++count;
                    }
                    direction = 'D';
                    --j;
                    ++i;
                    break;
                case 'D':
                    while(i < r){
                        if(indicator[i][j] == 1)
                            break;
                        ans.push_back(matrix[i][j]);
                        indicator[i][j] = 1;
                        ++i;
                        ++count;
                    }
                    direction = 'L';
                    --i;
                    --j;
                    break;
                case 'L':
                    while(j >= 0){
                        if(indicator[i][j] == 1)
                            break;
                        ans.push_back(matrix[i][j]);
                        indicator[i][j] = 1;
                        --j;
                        ++count;
                    }
                    direction = 'U';
                    ++j;
                    --i;
                    break;
                case 'U':
                    while(i >=0){
                        if(indicator[i][j] == 1)
                            break;
                        ans.push_back(matrix[i][j]);
                        indicator[i][j] = 1;
                        --i;
                        ++count;
                    }
                    direction = 'R';
                    ++i;
                    ++j;
                    break;
                default:
                    break;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
