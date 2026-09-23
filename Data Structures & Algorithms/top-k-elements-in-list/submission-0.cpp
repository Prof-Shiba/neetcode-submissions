#include <unordered_map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       // if k == 1 and 3 is the most freq element we return 3
       // if k == 2 we return 3,2 since 2 is the second most freq etc
       // hash table where we use the num as the index, and have the count inside?
       std::unordered_map<int, int> m;
       std::vector<int> res;
       int n = 0;

       for (const auto& n : nums) {
        m[n]++;
       }

       std::vector<std::pair<int,int>> sorted_map(
        m.begin(), m.end()
       );

       std::sort(sorted_map.begin(), sorted_map.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
       });

       for (int i{}; i < k; i++) {
        res.push_back(sorted_map[i].first);
       }

       return res;
    }
};
