#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        // maybe we can create a hash for each str and
        // store each letter, then have a value for how many 
        // times they were used. immediately return false if not equal
        std::unordered_map<char, int> m1, m2;

        for (const auto& c : s) {
            m1[c]++;
        }

        for (const auto& c : t) {
            m2[c]++;
        }

        if (m1 == m2) return true;

        return false;
    }
};
