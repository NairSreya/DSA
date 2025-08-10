class Solution {
public:
    vector<vector<string>> partition(string s) {
        int ind;
        vector<string> arr;
        vector<vector<string>> res;
        fun(0, s, arr, res);
        return res;
        
    }

    void fun(int ind,string s, vector<string> arr, vector<vector<string>>& res ){
        if(ind == s.size()){
            res.push_back(arr);
            return;
        }

        for(int i=ind; i<s.size(); i++ ){
            if(isPalindrome(s, ind, i)){
                arr.push_back(s.substr(ind, i-ind+1));
                fun( i+1, s,  arr,  res );
                arr.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end ){
        while(start<end){
            if(s[start++] != s[end--] ){
                return false;
            }
        }
        return true;
    }
};