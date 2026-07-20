class Solution {
public:
    void solve(int ind,vector<int>&nums,int target,set<vector<int>>&st,vector<vector<int>>res,vector<int>temp){
        if(ind==nums.size() || target<0)return;
        if(target==0){
            sort(temp.begin(),temp.end());
            st.insert(temp);
            return;
        }
        if(target>=nums[ind]){
            temp.push_back(nums[ind]);
            target-=nums[ind];
            solve(ind,nums,target,st,res,temp);
            target+=nums[ind];
            temp.pop_back();
        }
        solve(ind+1,nums,target,st,res,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        set<vector<int>>st;
        vector<vector<int>>res;
        vector<int>temp;
        solve(0,nums,target,st,res,temp);
        for(auto t:st){
            res.push_back(t);
        }
        return res;
    }
};
