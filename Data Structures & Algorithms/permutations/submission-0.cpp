class Solution {
public:
    void solve(vector<int>&nums,vector<int>&temp,unordered_set<int>&st,vector<vector<int>>&res){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!st.contains(nums[i])){
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(nums,temp,st,res);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        unordered_set<int>st;
        vector<int>temp;
        solve(nums,temp,st,res);
        return res;
    }
};
