#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> my_set;

        for (const auto& n : nums) {
            if (my_set.contains(n)) {
                return true;
            }
            else {
                my_set.insert(n);
            }
        }

        return false;
    }
};