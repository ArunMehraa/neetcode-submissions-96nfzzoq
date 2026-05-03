class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int n=s.size();
        int i=0,j=0;
        int len = 0;
        int maxi = 0;
        while(j<n){
            mp[s[j]]++;
            maxi = max(maxi,mp[s[j]]);
            if((j-i+1)-maxi > k){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
            len = max(len,j-i);
        }
        return len;
    }
};
