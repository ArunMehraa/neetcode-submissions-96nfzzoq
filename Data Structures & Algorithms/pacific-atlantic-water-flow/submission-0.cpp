class Solution {
public:
    bool isValid(int row,int col,int n,int m){
        return (row>=0 && row<n && col>=0 && col<m);
    }
    int r[4] = {1,0,-1,0};
    int c[4] = {0,1,0,-1}; 
    bool pacific(int row,int col){
        if(row==0 || col==0)return true;
        return false;
    }
    bool atlantic(int row,int col,int n,int m){
        if(row==n-1 || col==m-1)return true;
        return false;
    }
    bool solve(int row,int col,int n,int m,vector<vector<int>>& heights){
        queue<pair<int,int>>q;
        q.push({row,col});
        vector<vector<int>>vis(n,vector<int>(m,-1));
        vis[row][col] = 1;
        bool a = false;
        bool b = false;
        while(!q.empty()){
            int roww = q.front().first;
            int coll = q.front().second;
            q.pop();
            a = a | pacific(roww,coll);
            b = b | atlantic(roww,coll,n,m);
            if(a && b)return true;
            for(int i=0;i<4;i++){
                int rr = roww+r[i];
                int cc = coll+c[i];
                if(isValid(rr,cc,n,m) && vis[rr][cc]==-1 && heights[roww][coll]>=heights[rr][cc]){
                    q.push({rr,cc});
                    vis[rr][cc] = 1;
                }
            }
        }
        return a&&b;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(solve(i,j,n,m,heights)){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};
