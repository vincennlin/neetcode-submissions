class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int products = 1;
        int zeroCount = 0;

        for (int num : nums) {
            if (num != 0) {
                products *= num;
            } else {
                zeroCount++;
            }
        }

        if (zeroCount > 1) {
            return vector<int>(nums.size(), 0);
        }
        
        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (zeroCount > 0) {
                result[i] = (nums[i] == 0) ? products : 0;
            } else {
                result[i] = products / nums[i];
            }
        }

        return result;
    }
};