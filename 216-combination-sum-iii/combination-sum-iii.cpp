class Solution {
public:
    set<vector<int>> s;
    void getcombin(int k, int n, int idx, vector<vector<int>>& ans, vector<int>& combin){

        if(combin.size() > k || n < 0 ){
            return;
        }

        if(n==0 && combin.size()==k){
            if(s.find(combin) == s.end()){
                ans.push_back(combin);
                s.insert(combin);
                return;
            }
        }
        
        for(int i = idx; i <= 9; i++){
        //include
        combin.push_back(i);
        getcombin(k, n-i, i+1, ans, combin);

        //notinclude
        combin.pop_back();
        getcombin(k, n, i+1, ans, combin);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> combin;
        getcombin(k, n, 1, ans, combin);

        return ans;
    }
};