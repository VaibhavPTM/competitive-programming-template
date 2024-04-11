/**
 * Description: Dijkstra (Find shortest path from single source)
 * Usage: dijkstra O((V + E) lg(V))
 * Source: https://github.com/dragonslayerx
 */
const int MAX = 100050;
const int INF = 1e9;

void dijkstra(vector< vector< pair<int,int> > > &G, int vertexCount, int src, int dist[]){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    bool isvisited[MAX];

    for (int i = 0; i < vertexCount; i++) {
        dist[i] = INF;
        isvisited[i] = false;
    }

    dist[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty()){
        pair<int, int> tp = pq.top();
        pq.pop();
        int node = tp.second;
        int d = tp.first;
        if (!isvisited[node]) {
            isvisited[node] = true;
            for (int i = 0; i < G[node].size(); i++) {
                int v = G[node][i].first;
                int w = G[node][i].second;
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
    }
}
vi dijkstra(int sorce, int n = 0)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dis(n, 1e18), vis(n);
    pq.push({0, sorce});
    dis[sorce] = 0;
    while (!pq.empty()){
        pair<ll,ll> cur=pq.top(); 
        pq.pop(); 
        if(vis[cur.ss] == 1) continue;
        for(auto child:g[cur.second]){ 
            if(cur.first + child.second < dis[child.first]){
                dis[child.first]=cur.first+child.second;
                pq.push({dis[child.first], child.first});
            }
        }
        vis[cur.ss] = 1;
    }
    return dis;
}
void dijkstra(ll n)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    ll par[n + 1] = {0};
    vector<ll> dis(n + 1, 1e18), vis(n+1);
    pq.push({0, 1});
    dis[1] = 0;
    par[1] = 1;
    while (!pq.empty()){
        pair<ll,ll> cur=pq.top(); 
        pq.pop(); 
        if(vis[cur.ss] == 1) continue;
        for(auto child:graph[cur.second]){ 
            if(cur.first + child.second < dis[child.first]){
                dis[child.first]=cur.first+child.second;
                pq.push({dis[child.first], child.first});
                par[child.first] = cur.second; 
            }
        }
        vis[cur.ss] = 1;
    }
    if (dis[n] >= (ll)1e18 || par[n] == 0)
       { cout << -1 << endl; return;}
    vector<ll> ans;
    while (n != 1)
    {
        ans.push_back(n);
        n = par[n];
    }
    ans.push_back(1LL);
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << '\n';
}
