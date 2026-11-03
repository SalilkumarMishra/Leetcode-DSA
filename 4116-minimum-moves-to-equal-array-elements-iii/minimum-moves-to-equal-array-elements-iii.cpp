class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxi = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>maxi)
            {
                maxi = nums[i];
            }
        }
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            ans += maxi - nums[i];
        }
        return ans;
    }
};