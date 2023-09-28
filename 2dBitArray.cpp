s1(int, n);
    vi ar(n);
    sin(ar);
    vv (int) dp(n+1, vi (32));
    for(int i = 1; i <= n; i++) {
        int d = ar[i-1];
        for(int j = 0; j < 32; j++) {
            if(d & (1 << j)) {
                dp[i][j] += dp[i-1][j] + 1;
            }
        }
    }
