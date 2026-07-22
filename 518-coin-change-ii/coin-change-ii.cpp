class Solution {
public:
    int dp[301][5001];
    int solve(int i, int amount, vector<int>& coins)
    {
        if(amount==0)
        {
            return 1;
        }
        if(i==coins.size())
        {
            return 0;
        }
        if(dp[i][amount]!=-1)
        {
            return dp[i][amount];
        }
        int take = 0;
        int skip = 0;
        if(coins[i]<=amount)
        {
            take = solve(i,amount-coins[i],coins);
        }
        skip = solve(i+1,amount,coins);
        return dp[i][amount] = take+skip;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,amount,coins);
    }
};