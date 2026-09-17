#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       // we can have a hash map and add every num in there,
       // but prior check for target - our num and see if the result is in there 
       std::unordered_map<int, int> my_map;
       // store value as key, index as value, otherwise it comes out backwards and f'd up
       std::vector<int> ans;
       int res = 0;

       for (int i{}; i < nums.size(); i++) {
        res = target - nums[i];
        auto it = my_map.find(res);

        if (it != my_map.end()) {
            ans.push_back(it->second);
            ans.push_back(i);
            return ans;
        }
        else {
            my_map.insert({nums[i], i});
        }
       }
       return ans;
    }
};