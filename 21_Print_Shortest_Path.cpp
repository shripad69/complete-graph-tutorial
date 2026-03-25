#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        vector <int> dist(n + 1, INT_MAX);
        vector <int> par (n + 1);
        for (int i = 0; i < n + 1; i++) {
            par[i] = i;
        }

        vector <vector <pair <int, int>>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];

            adj[u].push_back({weight, v});
            adj[v].push_back({weight, u});
        }

        priority_queue < pair <int, int>, vector < pair <int, int>>, greater < pair <int, int>>> pq;
        dist[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {
            auto distance = pq.top().first;
            auto node = pq.top().second;
            pq.pop();

            if (dist[node] < distance) continue;

            for (auto i : adj[node]) {
                auto adjNode = i.second;
                auto adjWeight = i.first;

                if (dist[adjNode] > distance + adjWeight) {

                    
                    dist[adjNode] = distance + adjWeight;
                    par[adjNode] = node;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }


        if (dist[n] == INT_MAX) return {-1}; 

        int node = n;
        vector <int> ans;

        while (node != par[node]) {
            ans.push_back(node);
            node = par[node];
        }
        ans.push_back(node);
        ans.push_back(dist[n]);

        reverse(ans.begin(), ans.end());

        return ans;

    }
};