// link : https://codeforces.com/contest/1884/problem/C
void solve() {
    s2(int, n, m);
    vpi ar(n);
    sin(ar);
    sort(all(ar));
    print(ar);
    map<int,int> num1, numm;
    for(int i = 0; i < n; i++) {
        int x = ar[i].ff, y = ar[i].ss;
        if(x!=1) {
            num1[x]++;
            num1[y+1]--;
        }
        if(y!=m) {
            numm[x]++;
            numm[y+1]--;
        }
    }
    int pre=0;
    int ans=0;
    for(auto it:num1) {
        it.second=it.second+pre;
        pre=it.second;
        ans=max(ans,pre);
    }
    pre=0;
    for(auto it:numm) {
        it.second=it.second+pre;
        pre=it.second;
        ans=max(ans,pre);
    }
    cout<<ans<<"\n";
}
