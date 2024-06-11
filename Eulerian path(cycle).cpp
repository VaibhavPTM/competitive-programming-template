#define N 200001
vector<pair<int,int>> g[N];
int n, m;
int d[N];

void solve() {
    cin >> n >> m;    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[v].pb({u, i});
        g[u].pb({v, i});
        d[u]++, d[v]++;
    }
    for(int i = 1; i <= n; i++) {
        if(d[i] % 2) {
            print("IMPOSSIBLE");
            return;
        }
    }
    int start = 1;
    stack<int> st;
    
    vector<int> vis(m+1);
    vector<int> res;
    st.push(start);
    while(st.size()) {
        int tp = st.top();
        if(g[tp].size() > 0) {
            int node = g[tp].back().ff, idx = g[tp].back().ss;
            g[tp].pop_back();
            if(vis[idx] == 0) {
                st.push(node);
                vis[idx] = 1;
            }
        }
        else {
            res.push_back(tp);
            st.pop();
        }
    }
    if(res.size() != m + 1)
        print("IMPOSSIBLE");
    else 
        print(res);
}
 
