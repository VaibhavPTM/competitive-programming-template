vector<int> bfs(vector<vector<int>>& adj, int root) {
    int N = adj.size() - 1; // Number of vertices
    vector<int> dist(N + 1, -1); // Initialize distances to -1 (unvisited)
    queue<int> q;
    q.push(root);
    dist[root] = 0; // Distance to the root node is 0
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) { // If v is unvisited
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}
