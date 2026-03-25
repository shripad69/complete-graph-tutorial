#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:

    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        // Min-heap storing {distance, node}
        // Always gives the node with smallest distance first
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // Distance array → initialize all distances as infinity
        vector<int> dist(V, INT_MAX);

        // Adjacency list → {node -> {adjacent_node, weight}}
        vector<vector<pair<int, int>>> adj(V);

        // Step 1: Build graph from edge list
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});  // remove if graph is directed
        }

        // Step 2: Initialize source
        dist[src] = 0;
        pq.push({0, src});

        // Step 3: Process nodes using greedy approach
        while (!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int d = top.first;   // current distance
            int u = top.second;  // current node

            // Skip if this is an outdated entry (important optimization)
            if (d > dist[u]) continue;

            // Step 4: Relax all adjacent edges
            for (auto &it : adj[u]) {

                int v = it.first;
                int wt = it.second;

                // Relaxation condition:
                // If a shorter path to v is found via u
                if (dist[v] > d + wt) {

                    dist[v] = d + wt;       // update distance
                    pq.push({dist[v], v});  // push updated distance
                }
            }
        }

        // Final shortest distances from source to all nodes
        return dist;
    }
};