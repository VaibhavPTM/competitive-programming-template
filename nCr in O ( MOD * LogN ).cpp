  int mod = 1000003;
    vector<int> fac;
    vector<int> fac_inv;
    int power(int n, int m) {
        int res = 1;
        n %= mod;
        while(m > 0) {
            if(m & 1) {
                res = (1LL * res * n)%mod;
                m--;
            } else {
                n = (1LL * n * n)%mod;
                m /= 2;
            }
        }
        return res%mod;
    }
    int fermat(int n, int r) {
        n %= mod, r %= mod;
        if(n < r) return 0;
        if(r == 0 || n == r) return 1;
        return (1LL * fac[n] * fac_inv[r] * fac_inv[n-r])%mod;
    }
    long long lucas(long long n,long long r){
        if(r == 0) return 1;
        int ni = n % mod, ri = r % mod;
        return (lucas(n/mod,r/mod) * fermat(ni,ri)) % mod;
    }
