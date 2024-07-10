class Hash {
public:
    string s;
    vi p, hash;
    int n;
    int factor = 131;
    vi inv;
    Hash(string s_) {
        s = s_;
        n = s.size();
        p.resize(n+1);
        hash.resize(n+1);
        inv.resize(n+1);
    }

    void build() {
        p[0] = 1;
        for(int i = 1; i <= n; i++) {
            p[i] = (p[i-1] * factor) % MOD;
        }
        for(int i = 0; i <= n; i++) {
            inv[i] = mod_inv(p[i]) % MOD;
        }
        for(int i = 1; i <= n; i++) {
            int c = s[i-1] - 'a' + 1;
            hash[i] = (hash[i-1] + (c * p[i-1]) % MOD) % MOD;
        }
    }
    int get(int l, int r) {
        int res = ((hash[r] + MOD) - hash[l-1]) % MOD;
        res = (res * inv[l-1]) % MOD;
        return res;
    }
};
