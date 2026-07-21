class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
        int left = 0;
        int length = 0;

        for (int right = 0; right < s.size(); right++) {
            if (charMap.find(s[right]) != charMap.end()) {
                left = max(charMap[s[right]] + 1, left);
            }
            charMap[s[right]] = right;
            length = max(length, right - left + 1);
        }

        return length;
    }
};
