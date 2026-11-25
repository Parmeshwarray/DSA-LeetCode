class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;

        for(int i = 0; i < k; i++){
            sum += nums[i];
        }

        double maxAvg = (double)sum / k;

        for(int i = k; i < n; i++){
            sum += nums[i];     // Add incoming element
            sum -= nums[i-k];   // Remove outgoing element

            maxAvg = max(maxAvg, (double)sum / k);
        }

        return maxAvg;
    }
};