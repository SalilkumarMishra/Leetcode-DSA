class Solution {
    int dp[1001][1001];
    int rec(int l,int r,string &s)
    {
        if(l>r)
        {
            return 0;
        }
        if(l==r)
        {
            return 1;
        }
        if(dp[l][r]!=-1)
        {
            return dp[l][r];
        }
        int ans=max(rec(l+1,r,s),rec(l,r-1,s));
        if(s[l]==s[r])
        {
            ans=max(ans,rec(l+1,r-1,s)+2);
        }
        return dp[l][r]=ans;
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,n-1,s);
    }
};