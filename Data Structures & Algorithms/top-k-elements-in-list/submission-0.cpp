class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        for (int num : nums) {
            count[num] = count[num] + 1;
        }

        for (const auto& entry : count) {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> result;

        for (int i = freq.size() - 1; i > 0; i--) {
            for (int n : freq[i]) {
                result.push_back(n);
                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};
