class Solution {
public: 
    void merge(vector<int>& nums, int st, int mid, int end, vector<int>& temp){
        int i = st, j = mid+1;
        while(i <= mid && j <= end){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        //for remaining elements
        while(i <= mid){ //for left half
            temp.push_back(nums[i]);
            i++;
        }

        while(j <= end){ //for right half
            temp.push_back(nums[j]);
            j++;
        }

        //copy the temp array into original array
        for(int idx = 0; idx < temp.size(); idx++){
            nums[st+idx] = temp[idx];
        }
        temp.clear();
    }
    void mergesort(vector<int>& nums, int st, int end, vector<int>& temp){
        if(st < end){
            int mid = st+(end-st)/2;
            mergesort(nums,st,mid,temp);
            mergesort(nums,mid+1,end,temp);
            merge(nums,st,mid,end,temp);
        } 
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp;
        mergesort(nums,0,nums.size()-1,temp);
        return nums;
    }
};