class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(int num : nums){
            if(st.contains(num))return true;
            st.insert(num);
        }
        return false;
    }
};