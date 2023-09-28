
// this will give a factor pair wise
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

// this will give all prime factors of numbers
vector<ll> primeFactors(ll n) {
    vector<ll> p;
    while (n % 2 == 0) {
        p.push_back(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            p.push_back(i);
            n = n/i;
        }
    }
    if (n > 2) p.push_back(n);
//     cout << p.size() << endl;
    return p;
}
