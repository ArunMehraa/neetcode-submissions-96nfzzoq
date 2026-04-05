class Solution {
public:
    bool alpha(char ch){
        if ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int n = s.size();
        int i=0,j=n-1;
        while(i<j){
            bool b = alpha(s[j]);
            while(i<j && !alpha(s[i])){
                i++;
            }
            while(j>i && !alpha(s[j])){
                j--;
            }
            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
