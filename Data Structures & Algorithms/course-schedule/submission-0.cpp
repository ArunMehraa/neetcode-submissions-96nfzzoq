class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>adj[n];
        vector<int>inde(n,0);
        for(auto it:pre){
            adj[it[0]].push_back(it[1]);
            inde[it[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(inde[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(int i=0;i<adj[node].size();i++){
                int val = adj[node][i];
                inde[val]--;
                if(inde[val]==0){
                    q.push(val);
                }
            }
        }
        return count==n;
    }
};