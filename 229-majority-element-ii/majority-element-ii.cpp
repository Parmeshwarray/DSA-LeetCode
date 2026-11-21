class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int>m;
        for(int i=0; i<n; i++){
            m[nums[i]] ++;
            if(m[nums[i]] > n/3 &&  find(ans.begin(), ans.end(), nums[i]) == ans.end()) {
            ans.push_back(nums[i]);
        }
        }
        return ans;
    }
};