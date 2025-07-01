class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int, int> mpp;

        for(int i=0;i<arr.size();i++){
            int n = arr[i];
            int req = target-n;
            if(mpp.find(req)!=mpp.end()){
                return{mpp[req],i};
            }else{
                mpp[n] = i;
            }
        }
        return { -1, -1};
        
    }
};