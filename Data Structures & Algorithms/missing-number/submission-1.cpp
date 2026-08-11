class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int flag = 0;
        
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) flag=1;
            sum+=nums[i];
        } 
        int t = ((n+1)*n)/2;
        if(sum==t) {
            if(!flag)return 0;
            return nums.size();
        }
        else return t-sum;
    }
};