class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size(), ans=0;
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(r, vector<int>(c, -1));

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }
        vector<int>dir={-1,0,1, 0, -1};
        while(!q.empty()){
            int gr=q.front().first.first, gc=q.front().first.second, time=q.front().second;
            q.pop();
            ans=max(ans, time);
            for(int i=0; i<4; i++){
                int nr=gr+dir[i], nc=gc+dir[i+1];
                if(nr>=0 && nr<r && nc>=0 && nc<c && grid[nr][nc]==1 && vis[nr][nc]==-1){
                    q.push({{nr,nc}, time+1});
                    vis[nr][nc]=1;
                }
            }
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==1 && vis[i][j]==-1){ return -1;}
            }
        }

        return ans;
    }
};