v(p(int,int)) factor(int n) {
    v(p(int,int)) ar;
    ar.pb({1, n});
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            ar.pb({i, n / i});
        }
    }
    return ar;
}
