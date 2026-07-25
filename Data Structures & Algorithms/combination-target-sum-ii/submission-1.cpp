class Solution {
public:
    void solve(int ind,vector<int>&candi,int target,vector<int>&temp,vector<vector<int>>&res){
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(ind>=candi.size())return;
        if(candi[ind]<=target){
            temp.push_back(candi[ind]);
            solve(ind+1,candi,target-candi[ind],temp,res);
            temp.pop_back();
        }
        while(ind<candi.size()-1 && candi[ind]==candi[ind+1]){
            ind++;
        }
        solve(ind+1,candi,target,temp,res);
    }
    vector<vector<int>> combinationSum2(vector<int>& candi, int target) {
        sort(candi.begin(),candi.end());
        vector<int>temp;
        vector<vector<int>>res;
        solve(0,candi,target,temp,res);
        return res;
    }
};
