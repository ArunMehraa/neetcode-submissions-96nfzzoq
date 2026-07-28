class Solution {
public:
    int solve(int ind,vector<int>&nums,vector<int>&dp){
        if(ind>=nums.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int a = 0,b = 0;
        a = nums[ind]+solve(ind+2,nums,dp);
        b = solve(ind+1,nums,dp);
        return dp[ind] = max(a,b);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+2,0);
        for(int i=n-1;i>=0;i--){
            dp[i] = max(nums[i]+dp[i+2] , dp[i+1]);
        }
        return dp[0];
    }
};
