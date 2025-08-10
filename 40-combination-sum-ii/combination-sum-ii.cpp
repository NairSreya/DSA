class Solution {
private:
    void comb(vector<int>& candidates, int target, vector<int> ans, vector<vector<int>>& result, int i){
        if(target == 0){
            result.push_back(ans);
            return;
        }
        if(i == candidates.size() || target<0){
            return;
        }
        if(candidates[i]<=target){
            ans.push_back(candidates[i]);
            comb(candidates,  target- candidates[i], ans,result,  i+1);
            ans.pop_back();
        }
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }
        comb(candidates,  target, ans,result,  i+1);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ans;
        vector<vector<int>> result;
        comb( candidates, target,ans, result, 0);
        return result;
        
    }
};