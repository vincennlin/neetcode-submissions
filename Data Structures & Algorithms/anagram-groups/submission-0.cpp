class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (const auto& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; i++) {
                key += ',' + to_string(count[i]);
            }
            map[key].push_back(s);
        }

        vector<vector<string>> result;

        for (const auto& pair : map) {
            result.push_back(pair.second);
        }

        return result;
    }
};