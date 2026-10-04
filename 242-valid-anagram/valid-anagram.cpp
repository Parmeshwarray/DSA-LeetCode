class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();

        if(n1 != n2){
            return false;
        }

       unordered_map<char,int> m1;
       unordered_map<char,int> m2;

       for(int val : s){
        m1[val] ++;
       }

       for(int val : t){
        m2[val] ++;
       }

       if(m1==m2){
        return true;
       } else {
        return false;
       }
    }
};