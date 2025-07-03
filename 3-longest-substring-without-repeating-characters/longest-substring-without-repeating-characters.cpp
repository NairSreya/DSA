#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        
        unordered_map<char, int> mpp;
        int count = 1;
        int maxCount = 1;
        
        mpp[s[0]] = 0; // Track the first character
        
        for (int i = 1; i < s.size(); i++) {
            char current = s[i];
            
            // If the character is new or not part of the current streak
            if (mpp.find(current) == mpp.end() || mpp[current] < i - count) {
                count++;
                maxCount = max(maxCount, count); // Update max here for growing streaks
            } else {
                maxCount = max(maxCount, count); // Update max before reset
                count = i - mpp[current]; // Reset streak
            }
            
            mpp[current] = i; // Update last seen position
        }
        
        return max(maxCount, count); // Final check
    }
};