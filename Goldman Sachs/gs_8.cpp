int CountWays(string s) {
    // Code here
    if (s[0] == '0')return 0;
    int mod = 1e9 + 7;
    int n = s.length();
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        string str = "";
        str += s[i - 2];
        str += s[i - 1];
        int num = stoi(str);
        dp[i] = 0;
        if (s[i - 1] == '0') {
            if (num <= 26 && num > 0)
                dp[i] = dp[i - 2];
            else return 0;
        } else {
            if (num <= 26 && s[i - 2] != '0')
                dp[i] = (dp[i - 2] % mod + dp[i - 1] % mod) % mod;
            else dp[i] = dp[i - 1];
        }

    }
    return dp[n] % mod;
}