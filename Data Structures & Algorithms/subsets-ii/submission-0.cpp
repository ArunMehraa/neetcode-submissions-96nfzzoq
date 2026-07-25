class Solution {
public:
    void solve(int ind,vector<int>&nums,vector<int>&temp,vector<vector<int>>&res){
        if(ind==nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        solve(ind+1,nums,temp,res);
        temp.pop_back();
        while(ind<nums.size()-1 && nums[ind]==nums[ind+1]){
            ind++;
        }
        solve(ind+1,nums,temp,res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>res;
        solve(0,nums,temp,res);
        return res;
    }
};
