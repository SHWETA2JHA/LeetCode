class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>&board, vector<vector<int>>&vis){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()){
            return;
        }
        if(vis[i][j]==1 || board[i][j]=='X')return;
        vis[i][j]=1;
        vector<int>dir={-1,0,1,0,-1};
        for(int k=0; k<4; k++){
            dfs(i+dir[k], j+dir[k+1], board, vis);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int r=board.size(),  c=board[0].size(); 
        vector<vector<int>>vis(r, vector<int>(c,-1));
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if((i==0 || j==0 || i==r-1 || j==c-1 )&& board[i][j]=='O' && vis[i][j]==-1){
                    dfs(i,j,board,vis);
                }
            }
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(vis[i][j]==-1 && board[i][j]=='O')board[i][j]='X';
            }
        }
    }
};