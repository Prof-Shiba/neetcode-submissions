// i originally tried sorting but it would be O(n log n)
// and also fails when theres one sequence thats lower than another
// in length...i watched the solution for this one

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::set<int> set_nums(nums.begin(), nums.end());
        auto end_set_nums = set_nums.end();
        int count = 0;

        for (auto& n : nums) {
            if (set_nums.find(n - 1) == end_set_nums) {
                int length = 0;
                while (set_nums.find(n + length) != end_set_nums) {
                    length++;
                }

                count = (length > count) ? length : count;
            }
        }

        return count;
    }
};
