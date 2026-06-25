class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int>a;
        for(int i =0;i<n;i++)
        {
            a.push(stones[i]);
        }
        while(a.size()>1)
        {
            int x= a.top();
            a.pop();
            int y= a.top();
            a.pop();
            if( x!=y)
            {
                a.push(abs(y-x));
            }
        }
        if(a.empty()) return 0;
        return a.top();
    }
};