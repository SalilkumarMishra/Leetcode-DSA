class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlen = 0;
        for(int i=0;i<n;i++)
        {
            unordered_map<char, int> ch;
            int len = 0;
            for(int j=i;j<n;j++)
            {
                ch[s[j]]++;
                if(ch[s[j]]>1)
                {
                    break;
                }
                len++;
                maxlen = max(maxlen, len);
            }
        }
        return maxlen;
    }
};