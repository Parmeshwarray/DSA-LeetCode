class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int prefixproduct = 1;
        int suffixproduct = 1;

        for(int i=0; i<n; i++){

            if(prefixproduct == 0) prefixproduct = 1;
            if(suffixproduct == 0) suffixproduct = 1;

            prefixproduct *= nums[i];
            suffixproduct *= nums[n-i-1];

            ans = max(ans, max(prefixproduct,suffixproduct));
        }
        return ans;
    }
};