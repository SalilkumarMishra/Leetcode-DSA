class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0;
        int r=0;
        int sum = 0;
        int ans = INT_MIN;
        while(n>r)
        {
            sum += nums[r];
            if(r-l+1==k)
            {
                ans = max(ans,sum);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return (double)ans/k;
    }
};