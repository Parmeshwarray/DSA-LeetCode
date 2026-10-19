class Solution {
public:
    bool palin(string s, int st, int end){
        while(st <= end){
            if(s[st] == s[end]){
                st++; end--;
            } else {
                return false;
            }
        }
        return true;
    }

    bool IsPalindrome(string s, int st, int end){
        while(st <= end){
            if(s[st] == s[end]){
                st++; end--;
            } else {
                if(palin(s,st+1,end)){
                    return true;
                } else if(palin(s,st,end-1)){
                    return true;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        return IsPalindrome(s, 0, s.size()-1);
    }
};