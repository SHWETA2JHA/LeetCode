class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r=mat.size(), c=mat[0].size(); 
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(r, vector<int>(c,-1));
        vector<vector<int>>dist(r, vector<int>(c,0));

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        vector<int>dir={-1,0,1,0,-1};
        while(!q.empty()){
            int cr=q.front().first.first, cc=q.front().first.second, steps=q.front().second;
            dist[cr][cc]=steps;
            q.pop();

            for(int i=0; i<4; i++){
                int nr=cr+dir[i], nc=cc+dir[i+1];
                if(nr>=0 && nc>=0 && nr<r && nc<c && vis[nr][nc]==-1){
                    q.push({{nr,nc}, steps+1});
                    vis[nr][nc]=1;
                }
            }
        }
        return dist;
    }
};