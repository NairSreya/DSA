class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        unordered_map<char,int> mpp;
        int count = 1;
        int maxCount = 1;

        mpp[s[0]] = 0;

        for(int i=1;i<s.size();i++){
            char current = s[i];
            if(mpp.find(current) == mpp.end() || mpp[current] < i - count){
                count++;
                maxCount = max(maxCount, count);
            }else{
                maxCount = max(count,maxCount);
                count = i - mpp[current];
            }
            mpp[current] = i;

        }
        return maxCount;
        
    }
};