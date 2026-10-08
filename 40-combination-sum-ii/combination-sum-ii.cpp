class Solution {
public:

    void getCombinations(vector<int>& arr, int idx, int target, vector<vector<int>>& ans, vector<int>& combination) {

        // Target reached
        if (target == 0) {
            ans.push_back(combination);
            return;
        }

        for (int i = idx; i < arr.size(); i++) {

            // Skip duplicate choices at the same level
            if (i > idx && arr[i] == arr[i - 1])
                continue;

            // Since array is sorted
            if (arr[i] > target)
                break;

            // Include
            combination.push_back(arr[i]);

            // i + 1 -> element cannot be reused
            getCombinations(arr, i + 1, target - arr[i], ans, combination);

            // Backtrack
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {

        vector<vector<int>> ans;
        vector<int> combination;

        // Important for duplicate handling
        sort(arr.begin(), arr.end());

        getCombinations(arr, 0, target, ans, combination);

        return ans;
    }
};