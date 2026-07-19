class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>v(26,0);
        int count = 0;
        int size = tasks.size();
        for(int i=0;i<size;i++){
            v[tasks[i]-'A']++;
        }
        priority_queue<int>q;
        for(int i=0;i<26;i++){
            if(v[i])q.push(v[i]);
        }
        while(!q.empty()){
            vector<int>temp;
            for(int i=0;i<=n;i++){
                if(q.size()){
                    temp.push_back(q.top());
                    q.pop();
                }
            }
            for(auto t:temp){
                if(t>1){
                    q.push(t-1);
                }
            }
            if(q.empty())count+=temp.size();
            else count+=(n+1);
        }
        return count;
    }
};