#include <unordered_map>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> my_map;

        for (auto& n : nums) {
            if (my_map.contains(n)) {
                return true;
            }
            else {
                my_map.insert({n, 0});
            }
        }

        return false;
    }
};