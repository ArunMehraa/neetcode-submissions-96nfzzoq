class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int>pq;
        for(auto i:stones){
            pq.push(i);
        }
        while(pq.size()>0){
            if(pq.size()==1)return pq.top();
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a==b)continue;
            pq.push(abs(a-b));
        }
        return 0;
    }
};
