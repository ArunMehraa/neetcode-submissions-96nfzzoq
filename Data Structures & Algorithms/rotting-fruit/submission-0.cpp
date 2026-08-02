class Solution {
public:
    bool isValid(int row,int col,int n,int m){
        return (row>=0 && row<n && col>=0 && col<m);
    }
    int r[4] = {1,0,-1,0};
    int c[4] = {0,1,0,-1};    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int size = q.size();
            bool flag = false;    
            for(int j=1;j<=size;j++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int rr = row+r[i];
                    int cc = col+c[i];
                    if(isValid(rr,cc,n,m) && grid[rr][cc]==1 ){
                        grid[rr][cc] = 2;
                        q.push({rr,cc});
                        flag = true;
                    }
                }
            }
            if(flag)res++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return res;
    }
};
