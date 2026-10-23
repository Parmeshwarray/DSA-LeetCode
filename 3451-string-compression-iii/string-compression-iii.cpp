class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int n = word.size();

        for(int i=0; i<n; i++){
            char ch = word[i];
            int count = 0;

            while(i<n && word[i]==ch && count<9){
                count++; i++;
            }

            string str = to_string(count);
            comp+= str;
            comp += ch;
           

            i--;
        }
        return comp;
    }
};