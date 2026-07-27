class Solution {
public:
    int solve(int idx,int sum,vector<int>& arr,vector<vector<int>> &dp)
    {
        if(idx>=arr.size())
        {
            return sum;
        }
        if(dp[idx][sum]!=-1)
        {
            return dp[idx][sum];
        }
        int x=INT_MAX;
        if(sum>=arr[idx])
        {
            x=solve(idx+1,sum-arr[idx],arr,dp);
        }
        int b = solve(idx+1,sum,arr,dp);
        return dp[idx][sum]=min(x,b);
    }
    int lastStoneWeightII(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(),arr.end(),0);
        int ts=sum;
        sum/=2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        int a = solve(0,sum,arr,dp);
        a=sum-a;
        int b=ts-a;
        return b-a;

    }
};