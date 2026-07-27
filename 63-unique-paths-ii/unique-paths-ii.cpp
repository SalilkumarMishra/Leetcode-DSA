class Solution {
public:
    int dp[101][101];
    int m;
    int n;
    int solve(int i,int j,vector<vector<int>>& ob)
    {
        if(i<0 || i>=m || j<0 || j>=n || ob[i][j]==1)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        int right = solve(i,j+1,ob);
        int left = solve(i+1,j,ob);
        return dp[i][j] = left+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        m = ob.size();
        n = ob[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,ob);
    }
};