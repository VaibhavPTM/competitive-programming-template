int fmpower(int a,int n) {
    int p=1;
    while(n>0) {
        if(n&1)
            p=((p%MOD)*(a%MOD))%MOD;
        a=((a%MOD)*(a%MOD))%MOD;
        n=n>>1;
    }
    return p;
}
