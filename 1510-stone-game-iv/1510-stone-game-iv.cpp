class Solution {
private:
    bool solve(int n, vector<int>&dp){
        if(n==0)return false;
        if(dp[n]!=-1)return dp[n];

        for(int i=1; i*i<=n; i++){
            int rem=n-(i*i);
            if(solve(rem, dp)==false){
               return dp[n]=true;
            }
        }
        return dp[n]=false;
    }
public:
    bool winnerSquareGame(int n) {
        //if(n==0)return false;
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};