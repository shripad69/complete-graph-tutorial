

// 🔹 Shortest Path in DAG using Topological Sort

// Step 1: Convert given edge list into adjacency list
//          adj[u] = list of {v, weight}

// Step 2: Perform Topological Sort using DFS
//          - Visit all nodes
//          - Push node into stack after visiting its neighbors
//          - Stack gives nodes in topological order

// Step 3: Initialize distance array
//          dist[source] = 0   (source = 0)
//          dist[others] = INF (1e9)

// Step 4: Process nodes in Topological Order
//          while stack not empty:
//              node = topo.top()
//              pop it
//
//              if node is reachable (dist[node] != INF):
//                  for all adjacent nodes (v, weight):
//                      relax edge:
//                      dist[v] = min(dist[v], dist[node] + weight)

// Step 5: Replace all INF values with -1
//          (means node is unreachable)

// Step 6: Return distance array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 🔹 DFS function to generate Topological Order
    void dfs(int node, vector<int>& vis, 
             vector<vector<pair<int,int>>>& adj, 
             stack<int>& st) {

        vis[node] = 1;

        for (auto &edge : adj[node]) {
            int nextNode = edge.first;

            if (!vis[nextNode]) {
                dfs(nextNode, vis, adj, st);
            }
        }

        // push after visiting all neighbors (post-order)
        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {

        // 🔹 Step 1: Build adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v, wt});
        }

        // 🔹 Step 2: Topological Sort
        vector<int> vis(V, 0);
        stack<int> topo;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, topo);
            }
        }

        // 🔹 Step 3: Initialize distances
        vector<int> dist(V, 1e9);
        dist[0] = 0;  // source node

        // 🔹 Step 4: Relax edges in topo order
        while (!topo.empty()) {
            int node = topo.top();
            topo.pop();

            // process only if node is reachable
            if (dist[node] != 1e9) {
                for (auto &edge : adj[node]) {
                    int v = edge.first;
                    int wt = edge.second;

                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // 🔹 Step 5: Mark unreachable nodes as -1
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};