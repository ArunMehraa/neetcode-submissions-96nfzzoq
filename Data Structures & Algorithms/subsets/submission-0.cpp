class Solution {
public:
    void solve(int ind,vector<int>&nums,vector<int>&temp,vector<vector<int>>&res){
        if(ind==nums.size()){
            res.push_back(temp);
            return;
        }
        solve(ind+1,nums,temp,res);
        temp.push_back(nums[ind]);
        solve(ind+1,nums,temp,res);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>res;
        solve(0,nums,temp,res);
        return res;
    }
};
