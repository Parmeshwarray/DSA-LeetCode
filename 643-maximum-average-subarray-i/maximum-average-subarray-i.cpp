class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxavg = 0;
        long long sum = 0;

        for(int i=0; i<k; i++){
            sum += nums[i];
        }

        maxavg = (double)sum/k;

        for(int i=k; i<n; i++){
            sum += nums[i];
            sum -= nums[i-k];

            maxavg = max(maxavg,(double)sum/k);
        }
        return maxavg;
    }
};