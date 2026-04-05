class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        unordered_set<int>st(nums.begin(),nums.end());
        int count=1;
        int res=1;
        for(int i=0;i<n;i++){
            if(st.count(nums[i]-1))continue;
            while(st.count(nums[i]+1)){
                count++;
                nums[i]++;
            }
            res = max(res,count);
            count=1;
        }
        return res;
    }
};
