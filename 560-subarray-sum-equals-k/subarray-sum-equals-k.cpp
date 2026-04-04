class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> count{{0, 1}};
        int prefix = 0, ans = 0;

        for (int num : nums) {
            prefix += num;
            ans += count[prefix - k];
            count[prefix]++;
        }

        return ans;
    }
};