/**
 * Description: Floyd Warshall (Find the all pair shortest path distances)
 * Usage: See below O(N^3)
 * Source: https://github.com/dragonslayerx
 */
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
/*
    vector<vector<int>> floyd_warshall(int n, vector<vector<int>> edge) {
        const int MAX = 100;
        const int INF = 1e9 + 5;
        int Adj[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Adj[i][j] = INF;
            }
            Adj[i][i] = 0;
        }
        for(auto i : edge) {
            int a = i[0], b = i[1], w = i[2];
            Adj[a][b] = min(Adj[a][b], w);
            Adj[b][a] = min(Adj[b][a], w);
        }
        vector<vector<int>> dist(MAX, vector<int> (MAX));
        // int dist[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = Adj[i][j];
            }
        }
        // Floyd Warshall Algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INF and dist[k][j] != INF) {
                        if (dist[i][j] > dist[i][k] + dist[k][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }
        }
        return dist;
    } 
*/
const int MAX = 100;
const int INF = 1e9 + 5;
int main(){
    int n;
    cin >> n;
    int Adj[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Adj[i][j] = INF;
        }
        Adj[i][i] = 0;
    }

    int countEdges;
    cin >> countEdges;
    for (int i = 0; i < countEdges; i++) {
        int a, b;
        int w;
        cin >> a >> b >> w;
        a--, b--;
        Adj[a][b] = min(Adj[a][b], w);
        Adj[b][a] = min(Adj[b][a], w);
    }

    int dist[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = Adj[i][j];
        }
    }
    // Floyd Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF and dist[k][j] != INF) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
