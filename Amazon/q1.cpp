int maxProfit(int K, int N, int A[]) {
    // code here
    int dp[K + 1][N + 1];
    memset(dp, 0, sizeof dp);


    for (int i = 1; i <= K; i++) {
        int mx = INT_MIN;
        for (int j = 1; j <= N; j++) {
            dp[i][j] = dp[i][j - 1];
            mx = max(mx, dp[i - 1][j - 1] - A[j - 1]);
            dp[i][j] = max(dp[i][j], mx + A[j - 1]);
        }
    }

    return dp[K][N];
}