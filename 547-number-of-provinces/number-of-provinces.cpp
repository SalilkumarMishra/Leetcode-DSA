class Solution {
public:
    void dfs(int node,vector<int>&vis, vector<vector<int>>& isc)
    {
        vis[node] =1;
        for(int i=0;i<isc.size();i++)
        {
            if(!vis[i] && isc[node][i]==1)
            {
                dfs(i,vis,isc);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isc) {
        int n =isc.size();
        vector<int> vis(n,0);
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                cnt++;
                dfs(i,vis,isc);
            }
        }
        return cnt;
    }
};