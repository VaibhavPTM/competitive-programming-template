
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
