class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int freq[26] = {0};
        for(char c : chars)
        {
            freq[c-'a']++;
        }
        int ans = 0;
        for(string word : words)
        {
            int temp[26];
            for(int i =0;i<26;i++)
            {
                temp[i] = freq[i];
            }

            bool possible = true;
            for(char c : word)
            {
                if(temp[c-'a']==0)
                {
                    possible = false;
                    break;
                }
                temp[c-'a']--;
            }
            if(possible)
            {
                ans += word.length();
            }
        }
        return ans;
    }
};