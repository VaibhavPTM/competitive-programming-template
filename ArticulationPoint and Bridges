    #define N 100001
    int time = 1;
    vector<int> g[N];
    set<int> a_point;
    int vis[N], low[N], dis[N];
    vector<vector<int> > bridge; 
    void dfs(int node, int par) {
        vis[node] = 1;
        low[node] = dis[node] = time++;
        int child = 0;
        for(int ch : g[node]) {
            if(vis[ch] == 0) {
                child++;
                dfs(ch, node);
                low[node] = min(low[node], low[ch]);
                // if(low[ch] > dis[node]) {
                //     bridge.push_back({node, ch});
                // }
                if(par != -1 && low[ch] >= dis[node]) {
                    a_point.insert(node);
                }
            }
            else if(ch != par) {
                low[node] = min(low[node], dis[ch]);
            }
        }
        if(par == -1 && child >= 2) {
            a_point.insert(node);
        }
    }
