class Solution {
public:
    void getcombin(vector<int>& nums,int i, vector<int>& combin, vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(combin);
            return;
        }

        combin.push_back(nums[i]);
        getcombin(nums,i+1,combin,ans);
        
        combin.pop_back();
        getcombin(nums,i+1,combin,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> combin;
        vector<vector<int>> ans;

        getcombin(nums,0,combin,ans);
        return ans;
    }
};