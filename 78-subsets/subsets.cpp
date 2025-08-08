class Solution {
private:
    void subsetSol(vector<int>& nums, int i, vector<int> currentSubSet, vector<vector<int>>& vect ){
        if(i == nums.size()){
            vect.push_back(currentSubSet);
            return;
            
        }

        //dont include        
        subsetSol(nums,i+1,currentSubSet, vect);

        //include
        currentSubSet.push_back(nums[i]);
        subsetSol(nums,i+1,currentSubSet, vect);
        currentSubSet.pop_back();

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> vect;
        vector<int> currentSubSet;
        subsetSol(nums,  0, currentSubSet,  vect );
        return vect;

    }
};