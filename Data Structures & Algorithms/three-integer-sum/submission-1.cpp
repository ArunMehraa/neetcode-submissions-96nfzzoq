class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            int start = i+1 , end = n-1;
            if(i!=0 && nums[i]==nums[i-1])continue;
            int target = 0-nums[i];
            while(start<end){
                int temp = nums[start]+nums[end];
                if(temp == target){
                    if(end==n-1 || nums[end]!=nums[end+1]){
                        res.push_back({nums[i],nums[start],nums[end]});
                    }
                    start++;
                    end--;
                }
                else if(temp>target){
                    end--;
                }
                else{
                    start++;
                }
            }
        }
        return res;
    }
};