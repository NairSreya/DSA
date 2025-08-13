class Solution {

public:
    bool canBreak(int start,string s, unordered_set<string> &wordSet, vector<int>& memo ){
        if(start == s.size()){
            return true;
        }
        if(memo[start]!=-1){
            return memo[start];
        }

        for(int end = start+1; end<=s.size(); end++){
            string prefix = s.substr(start, end-start);
            if(wordSet.find(prefix)!=wordSet.end() && canBreak(end, s , wordSet, memo)){
                return memo[start] =true;
            }
        }
        return memo[start] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(),-1);
        return canBreak(0,s, wordSet, memo);

        
    }
};