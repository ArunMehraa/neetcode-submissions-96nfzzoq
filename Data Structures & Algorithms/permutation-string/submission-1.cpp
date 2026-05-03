class Solution {
public:
    bool checkInclusion(string a, string b) {
        int n = a.size();
        int m = b.size();
        if(n>m)return false;
        int i=0,j=0;
        vector<int>vis(26,0);
        for(int i=0;i<n;i++){
            vis[a[i]-'a']++;
        }
        while(j<m){
            vis[b[j]-'a']--;
            while(vis[b[j]-'a']<0){
                vis[b[i]-'a']++;
                i++;
            }
            if(j-i+1==n)return true;
            j++;
        }
        return false;
    }
};
