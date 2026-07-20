class Solution {
public:
    int t=0;
    void solve(int i,int sum,vector<int>& nums, int target)
    {
        if(i==nums.size())
        {
            if(sum==target)
            {
                t++;
            }
            return;
        }
        solve(i+1,sum-nums[i],nums,target);
        solve(i+1,sum+nums[i],nums,target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        solve(0,0,nums,target);
        return t;
    }
};