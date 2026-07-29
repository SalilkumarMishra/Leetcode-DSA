class Solution {
public:
    int solve(int i,int j, vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        int n = matrix.size();
        if(j<0 ||j>=n)
        {
            return 1e9;
        }
        if(i==0)
        {
            return matrix[0][j];
        }
        if(dp[i][j] != INT_MAX)
        {
            return dp[i][j];
        }
        int up =solve(i-1,j,matrix,dp);
        int left = solve(i-1,j-1,matrix,dp);
        int right = solve(i-1,j+1,matrix,dp);
        return dp[i][j] = matrix[i][j] + min(up,min(left,right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        int ans = INT_MAX;
        for(int j=0;j<n;j++)
        {
            ans = min(ans,solve(n-1,j,matrix,dp));
        }
        return ans;
    }
};