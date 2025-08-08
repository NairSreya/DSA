class Solution {
private:
    void subset(vector<int>& nums, int i, vector<vector<int>>& result, vector<int> sub){
        if(i == nums.size()){
            result.push_back(sub);
            return;
        }

        sub.push_back(nums[i]);
        subset(nums, i+1, result, sub);
        sub.pop_back();

        while(i+1<nums.size() && nums[i+1]==nums[i]){
            i++;
        }
        subset(nums, i+1, result, sub);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> sub;
        subset(nums, 0, result,  sub);
        return result;   
        
    }
};