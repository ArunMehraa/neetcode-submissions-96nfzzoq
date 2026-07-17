class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>>q;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
            if(q.size()>k){
                q.pop();
            }
        }
    }
    
    int add(int val) {
        q.push(val);
        if(size<q.size())q.pop();
        return q.top();
    }
};
