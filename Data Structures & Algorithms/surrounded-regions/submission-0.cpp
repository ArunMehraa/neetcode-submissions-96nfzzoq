class Solution {
public:
    bool isValid(int row,int col,int n,int m){
        return (row>=0 && row<n && col>=0 && col<m);
    }
    int r[4] = {1,0,-1,0};
    int c[4] = {0,1,0,-1};    
    bool onEdge(int row,int col,int n,int m){
        if(row==n-1 || col==m-1 || row==0 || col==0){
            return true;
        }
        return false;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O' && onEdge(i,j,n,m)){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            vis[row][col] = 1;
            q.pop();
            for(int i=0;i<4;i++){
                int rr = row+r[i];
                int cc = col+c[i];
                if(isValid(rr,cc,n,m) && board[rr][cc]=='O' && vis[rr][cc]==-1){
                    q.push({rr,cc});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O' && vis[i][j]==-1){
                    board[i][j]='X';
                }
            }
        }
    }
};
