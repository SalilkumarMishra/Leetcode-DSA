class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mn = LLONG_MAX;
        long long mx = LLONG_MIN;

        for (int x : nums) {
            mn = min(mn, (long long)x);
            mx = max(mx, (long long)x);
        }

        return (mx - mn) * k;
    }
};