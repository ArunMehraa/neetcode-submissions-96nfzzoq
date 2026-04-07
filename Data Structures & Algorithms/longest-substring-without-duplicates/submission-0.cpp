class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0,j=0;
        int len=0;
        unordered_set<char>st;
        while(j<n){
            while(st.count(s[j])){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            len=max(j-i+1,len);
            j++;
        }
        return len;
    }
};
