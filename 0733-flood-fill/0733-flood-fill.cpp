class Solution {
private: 
    vector<int>dir = { -1, 0, 1, 0 ,-1};

    void solve(vector<vector<int>>& image, int r, int c, int prevC, int newC){
        if(r>=image.size() || c>=image[0].size() || r<0 || c<0)return;
        if(image[r][c]!=prevC) return;
        image[r][c]=newC;
        
        for(int i=0; i<4; i++){
            int nr=r+dir[i], nc=c+dir[i+1];
            solve(image, nr,nc, prevC, newC);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)return image;
        solve(image, sr, sc, image[sr][sc], color);
        return image;
    }
};