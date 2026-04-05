class Solution {
public:
    bool solve(string a,string b){
        if(a.size()!=b.size())return false;
        int n = a.size();
        vector<int>vec(26,0);
        for(int i=0;i<n;i++){
            vec[a[i]-'a']++;
            vec[b[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(vec[i]!=0)return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        int n = strs.size();
        vector<int>mark(n,0);
        for(int i=0;i<n;i++){
            vector<string>temp;
            if(mark[i]!=0)continue;
            mark[i]=1;
            temp.push_back(strs[i]);
            for(int j=i+1;j<n;j++){
                if(solve(strs[i],strs[j])){
                    temp.push_back(strs[j]);
                    mark[j]=1;
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
