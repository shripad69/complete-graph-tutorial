#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:

    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {


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


        set <pair <int, int>> st;

        st.insert({0, src});

        while (!st.empty()) {

            int distance = st.begin()->first;
            int node = st.begin()->second;
            st.erase({distance, node});

            for (auto i : adj[node]) {
                int v = i.first;
                int weight = i.second;

                if (dist [v] > weight + distance) {

                    if (dist[v] != INT_MAX) {
                        st.erase({dist[v], v});
                    }
                    dist[v] = weight + distance;
                    st.insert({dist[v], v});
                }
            }

        }

        return dist;
        
    }
};