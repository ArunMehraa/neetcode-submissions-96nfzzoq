class Solution {
public:
    int solve(int start,int end,vector<int>&nums){
        int n = nums.size();
        int curr=0,next=0,nextt=0;
        for(int i=end-1;i>=start;i--){
            curr = max(nums[i]+nextt , next);
            nextt = next;
            next = curr;
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        return max(solve(0,n-1,nums),solve(1,n,nums));
    }
};
