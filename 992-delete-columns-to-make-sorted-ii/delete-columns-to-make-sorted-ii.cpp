class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int deletions = 0;

        // ordered[i] = true means strs[i] < strs[i+1] is already confirmed
        vector<bool> ordered(n - 1, false);

        for (int col = 0; col < m; col++) {
            bool needDelete = false;

            // Check if this column breaks lexicographical order
            for (int i = 0; i < n - 1; i++) {
                if (!ordered[i] && strs[i][col] > strs[i + 1][col]) {
                    needDelete = true;
                    break;
                }
            }

            if (needDelete) {
                deletions++;
                continue;   // skip updating ordered
            }

            // Update ordered status
            for (int i = 0; i < n - 1; i++) {
                if (!ordered[i] && strs[i][col] < strs[i + 1][col]) {
                    ordered[i] = true;
                }
            }
        }

        return deletions;
    }
};
