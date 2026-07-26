class Solution {
public:
    bool solve(int row, int col, int ind, vector<vector<char>>& board,string word){
        if(ind==word.size())return true;
        if(row>=board.size() || col>=board[0].size())return false;
        if(board[row][col]!=word[ind])return false;
        if(board[row][col]=='*')return false;
        bool a=false,b=false,c=false,d=false;
        char ch = board[row][col];
        board[row][col]='*';
            a = solve(row-1,col,ind+1,board,word);
            b = solve(row+1,col,ind+1,board,word);
            c = solve(row,col-1,ind+1,board,word);
            d = solve(row,col+1,ind+1,board,word);
        board[row][col]=ch;
        return a||b||c||d;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0]==board[i][j]){
                    if(solve(i,j,0,board,word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
