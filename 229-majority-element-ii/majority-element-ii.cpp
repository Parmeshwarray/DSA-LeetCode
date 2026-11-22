class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int candidate1=0, count1=0, candidate2=0, count2=0;
        int freq1=0, freq2=0;
        for(int i=0; i<n; i++){
            if(nums[i] == candidate1){
             count1++;
            } else if(nums[i] == candidate2){
            count2++;
            } else if(count1 == 0){
            candidate1 = nums[i];
            count1 = 1;
            } else if(count2 == 0){
            candidate2 = nums[i];
            count2 = 1;
            } else{
            count1--;
            count2--;
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i] == candidate1){
                freq1++;
            } else if(nums[i] == candidate2){
                freq2++;
            }
        }
        if(freq1 > n/3){
            ans.push_back(candidate1);
        } 
        if(freq2 > n/3){
            ans.push_back(candidate2);
        } 
        return ans;
    }
};