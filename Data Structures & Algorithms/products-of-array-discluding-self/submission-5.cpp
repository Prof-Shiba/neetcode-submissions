class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // the question is asking
        // if we are at nums[0] where nums == [1,2,4,6]
        // then we should multiply all numbers together that arent pos 0
        // 2 * 4 * 6
        // then for nums[1] we multiply 1 * 4 * 6 etc
        // we multiply all numbers in the arr together except whatever num is at pos i
        vector<int> output;
        int total = 1;
        int zero_count = 0;

        for (const auto& n : nums) {
            if (n == 0)  {
                zero_count++;
            }
            else {
                total *= n;
            }
        }

        for (const auto& n : nums) {
            int res;

            if (zero_count > 1) {
                res = 0;
            }
            else if (zero_count == 1) {
                res = (n == 0) ? total : 0;
            }
            else {
                res = total / n;
            }

            output.push_back(res);
        }

        return output;
    }
};
