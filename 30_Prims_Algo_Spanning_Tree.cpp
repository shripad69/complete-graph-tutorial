#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {

        // adj[u] = {weight, v}
        vector<vector<pair<int, int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({wt, v});
            adj[v].push_back({wt, u}); 
        }

        // Min-heap: {weight, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> vis(V, 0); 
        int sum = 0;

        // Start from node 0 (weight = 0)

        // E * LOG (E)
        pq.push({0, 0});

        while (!pq.empty()) {

            auto [weight, node] = pq.top();
            pq.pop();

            // VERY IMPORTANT:
            // If node already included in MST → skip
            // (because PQ can contain multiple entries for same node)
            if (vis[node]) continue;

            vis[node] = 1;
            sum += weight;

            for (auto &it : adj[node]) {
                int adjNode = it.second;
                int adjWt = it.first;

                // Only consider unvisited nodes
                if (!vis[adjNode]) {
                    pq.push({adjWt, adjNode});
                }
            }
        }

        return sum;
    }
};