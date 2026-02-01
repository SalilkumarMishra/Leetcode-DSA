class Solution {
 public:
  int minimumCost(vector<int>& nums) {
    constexpr int k = 50;
    int m1 = k;
    int m2 = k;

    for (int i = 1; i < nums.size(); ++i)
      if (nums[i] < m1) {
        m2 = m1;
        m1 = nums[i];
      } else if (nums[i] < m2) {
        m2 = nums[i];
      }

    return nums[0] + m1 + m2;
  }
};