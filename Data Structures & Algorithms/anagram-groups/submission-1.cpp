#include <algorithm>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> anagrams;
       unordered_map<int, vector<string>> m;

       for (const auto& str : strs) {
        int ascii_val = 0;

        string sorted_str = str;
        std::sort(sorted_str.begin(), sorted_str.end());

        for (const auto& c : sorted_str) {
            // this can happen to add up to the same
            // value for different strs if doing ascii_val += c
            // (ex: ill & duh both equal 321)
            // ascii_val * ascii_val is order dependent and sorting fixes this
            ascii_val = ascii_val * ascii_val + c;
        }

        m[ascii_val].push_back(str);
       }

       for (const auto& [ascii, strings] : m) {
        anagrams.push_back(strings);
       }

       return anagrams;
    }
};