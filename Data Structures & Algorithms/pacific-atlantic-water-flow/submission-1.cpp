class Solution {
public:
    int row[4] = {1,0,-1,0};
    int col[4] = {0,1,0,-1};
    void solve(int n,int m,vector<vector<int>>&height,vector<vector<int>>&ocean,queue<pair<int,int>>&q){
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            ocean[r][c] = 1;
            q.pop();
            for(int i=0;i<4;i++){
                int rr = r+row[i];
                int cc = c+col[i];
                if(rr>=0 && cc>=0 && rr<n && cc<m && ocean[rr][cc]==-1 && height[r][c]<=height[rr][cc]){
                    q.push({rr,cc});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>res;
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>>pacific(n,vector<int>(m,-1));
        vector<vector<int>>atlantic(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)q.push({i,0});
        for(int i=0;i<m;i++)q.push({0,i});
        solve(n,m,heights,pacific,q);
        for(int i=0;i<n;i++)q.push({i,m-1});
        for(int i=0;i<m;i++)q.push({n-1,i});
        solve(n,m,heights,atlantic,q);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};