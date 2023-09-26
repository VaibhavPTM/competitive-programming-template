// Link : 
#include<bits/stdc++.h>

// #include<boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// #define i512      int512_t
// #define i256      int256_t
// #define i128      int128_t
// #define i1024     int1024_t
        
using namespace std;        
#define int                     long long
#define ll                      long long
#define TEST                    int t = 1; cin >> t; while(t--) solve();
#define p(A,B)                  pair<A,B>
#define pb                      push_back
#define all(v)                  v.begin(), v.end()
#define allr(v)                 v.rbegin(), v.rend()
#define v(T)                    vector<T> 
#define vi                      vector<int> 
#define vs                      vector<string > 
#define vvi                     vector<vector<int> > 
#define vvs                     vector<vector<string> > 
#define vpi                     vector<pair<int,int> > 
#define vv(T)                   vector<vector<T> >
#define maxhp(T)                priority_queue<T>
#define minhp(T)                priority_queue<T, vector<T> , greater<T> >
#define ff                      first
#define ss                      second
#define yes                     cout << "YES" << endl;
#define no                      cout << "NO" << endl;
#define ps(x,y)                 fixed<<setprecision(y)<<x
#define mem(n,i)                memset(n, i,sizeof n)
#define Case(i)                 cout << "Case #" << i << ": "
#define endl                    "\n"
#define p0(x)                   cout<<(x)<<" "
#define s1(A,a)                 A a; cin >> a
#define s2(A,a,b)               A a, b; cin >> a >> b
#define s3(A,a,b,c)             A a, b, c; cin >> a >> b >> c
#define s4(A,a,b,c,d)           A a, b, c, d; cin >> a >> b >> c >> d
#define s5(A,a,b,c,d,e)         A a, b, c, d, e; cin >> a >> b >> c >> d >> e
#define s6(A,a,b,c,d,e,f)       A a, b, c, d, e, f; cin >> a >> b >> c >> d >> e>> f
#define loop(i_itr, k, n)       for(int i_itr = k; i_itr <= n; i_itr++)
#define looprev(i_itr,n,a)      for(ll i_itr=n; i_itr>=a; i_itr--)
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ll mod = 998244353;


template <typename A, typename B>
void print (v(p(A,B)) &ar) { for(auto &i : ar) cout << i.ff << " " << i.ss << endl;}
template <typename A>
void print(v(A) ar[], int n) { for(int i = 0; i < n; i++) {cout << i << " --> "; {for(int j = 0; j < ar[i].size(); j++){cout << ar[i][j] << " "; } cout << endl; }}}
template <typename T>
void print(v(v(T)) &ar) { for(int i = 0; i < ar.size(); i++) { for(int j = 0; j < ar[i].size(); j++){ cout << ar[i][j] << " "; } cout << endl; } }
template <typename A>
void print (v(A) &ar) { for(A &i : ar)  cout << i << " "; cout << endl; }
template <typename A>
void print (set<A> &ar) { for(auto &i : ar)  cout << i << " "; cout << endl; }
template <typename T>
void print(T t) { cout << t << '\n' ;}
template<typename T, typename... Args>
void print(T t, Args... args) {cout << t << " "; print(args...) ;}

template <typename A>
void sin (v(A) &ar) { for(A &i : ar)  cin >> i; }
template <typename T>
void sin(v(v(T)) &ar) { for(int i = 0; i < ar.size(); i++) { for(int j = 0; j < ar[i].size(); j++){ cin >> ar[i][j]; } } }
template <typename A, typename B>
void sin (v(p(A,B)) &ar) { for(auto &i : ar) { cin >> i.ff >> i.ss; } }
template <typename T>



bool prime(ll n) {if(n == 1) return false; for(int i = 2; i * i <= n; i++) if(n % i == 0) return false;return true;}
ll POW (ll a, ll p, ll m) { ll res = 1; while (p > 0) { if(p % 2 == 0){ p /= 2; a = ((a%m)*(a%m))%m;} else{ res = ((res%m)*(a%m))%m; p--; }}return res;}
ll mod_mul(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD;}
ll mod_add(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD;}
ll bs_sqrt(ll x) { ll left = 0, right = 2000000123; while (right > left) { ll mid = (left + right) / 2; if (mid * mid > x) right = mid;else left = mid + 1;}return left - 1;}
ll ceilDiv(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll getsum(ll n) {return (n*(n+1))/2;}
int nextGratDivNum(int l, int i) {return (ceilDiv(l, i)) * i;}
int sumSeire(int a, int l, int n) {int res = 0;if(n % 2 == 0) {res = ((a + l) * (n / 2));}else res = ((a + l)/2) * n;return res;}

v(int) xx = {1,-1,0,0,1,-1,1,-1};
v(int) yy = {1,-1,1,-1,-1,1,0,0};
v(int) xs = {0,0,1,-1};
v(int) ys = {1,-1,0,0};


void solve() {
    
}
    
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);

#ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    TEST
    // solve();
    return 0;
}   
