class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int >>dp(coins.size()+1);
        for(int i=0;i<=n;i++){
            vector<int>t(amount+1,0);
            dp[i]=t;
        }
            for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

     
        // now i have to fill rest of the subproblmes
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(j<coins[i-1]){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    
                    // NOT TAKE + TAKE
                    if(dp[i-1][j] > INT_MAX - dp[i][j-coins[i-1]]) {
                        dp[i][j] = INT_MAX;
                    }
                    else {
                        dp[i][j] =
                            dp[i-1][j] +
                            dp[i][j-coins[i-1]];
                    }
                }
            }
        }
        return dp[n][amount];
    }
};
