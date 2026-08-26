class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>adj[n];
        vector<int>inde(n,0);
        for(auto it:pre){
            adj[it[1]].push_back(it[0]);
            inde[it[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(inde[i]==0){
                q.push(i);
            }
        }
        vector<int>res;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int i=0;i<adj[node].size();i++){
                int val = adj[node][i];
                inde[val]--;
                if(inde[val]==0){
                    q.push(val);
                }
            }
        }
        if(res.size()==n)return res;
        return {};
    }
};
