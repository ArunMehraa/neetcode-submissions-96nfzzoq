class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        set<vector<int>>st;
        for(int i=0;i<n;i++){
            int start = i+1 , end = n-1;
            int target = 0-nums[i];
            while(start<end){
                int temp = nums[start]+nums[end];
                if(temp == target){
                    if(!st.count({nums[i],nums[start],nums[end]})){
                        st.insert({nums[i],nums[start],nums[end]});
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
