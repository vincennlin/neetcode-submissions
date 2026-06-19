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

        vector<int> result;

        if (zeroCount > 1) {
            for (int i = 0; i < nums.size(); i++) {
                result.push_back(0);
            }
            return result;
        } else if (zeroCount == 1) {
            for (int num : nums) {
                if (num != 0) {
                    result.push_back(0);
                } else {
                    result.push_back(products);
                }
            }
        } else {
            for (int num : nums) {
                result.push_back(products / num);
            }
        }


        return result;
    }
};
