class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0; 
        int high = n-1;
        int x= target;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]==x)
            {
                return mid;
            }
            else if(nums[mid]>x)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
            return -1;
        
    }
};