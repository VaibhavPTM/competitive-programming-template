    int n;
    cin >> n;
    vi ar(n);
    sin(ar);

    int BITSIZE = 32;
    vv (int) dp(n+1, vi (BITSIZE));
    for(int i = 1; i <= n; i++) {
        int d = ar[i-1];
        for(int j = 0; j < BITSIZE; j++) {
            if(d & (1ll << j)) {
                dp[i][j] += dp[i-1][j] + 1;
            }
        }
    }
    print(dp);
