class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> indexMap;

        // Store indices of each number
        for (int i = 0; i < nums.size(); i++) {
            indexMap[nums[i]].push_back(i);
        }

        int minDistance = INT_MAX;

        // Check each number's indices
        for (auto &entry : indexMap) {
            vector<int> &indices = entry.second;

            // Need at least 3 occurrences
            for (int i = 0; i + 2 < indices.size(); i++) {
                int first = indices[i];
                int third = indices[i + 2];

                int distance = 2 * (third - first);
                minDistance = min(minDistance, distance);
            }
        }

        return (minDistance == INT_MAX) ? -1 : minDistance;
    }
};