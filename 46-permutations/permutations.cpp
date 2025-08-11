class Solution {
public:
    void perm(vector<int>& nums, vector<int>& path, vector<vector<int>>& result, vector<bool>& used){
        if(path.size() == nums.size()){
            result.push_back(path);
            return ;
        }

        for(int i=0; i<nums.size(); i++){
            if(used[i]){
                continue;
            }

            //mark the new element
            used[i] = true;
            path.push_back(nums[i]);
            
            perm(nums, path, result, used);

            path.pop_back();

            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        perm(nums, path, result, used);
        return result;
        
    }
};