class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int i=0; i<n; i++)dp[i][i]=piles[i];

        for(int len=2; len<=n; len++){
            for(int j=0; j+len-1<n; j++){
                int i=j+len-1;
                int takel=piles[j]+dp[j+1][i];
                int taker=piles[i]+dp[j][i-1];
                dp[j][i]=max(takel, taker);
            }
        }

        return dp[0][n-1]>0;
    }
};