class Solution {
public:
    void subset(vector<int>& nums, vector<vector<int>>& ans,int i, vector<int>& res){
        if(i == nums.size()){
            ans.push_back(res);
            return;
        }

        res.push_back(nums[i]);
        subset(nums,ans,i+1,res);
        //backtrack
        res.pop_back();
        int idx = i+1;

        while(idx < nums.size() && nums[idx]==nums[idx-1]){
            idx++;
        }

        subset(nums,ans,idx,res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> res;

        subset(nums,ans,0,res);
        return ans;
    }
};