class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(),costs.end());
        int count=0;
        for(int i:costs)
        {
            if(i<=coins)
            {
                coins = coins- i ;
                count++;
            }
            else
            {
                break;
            }
        }
        return count;
    }
};