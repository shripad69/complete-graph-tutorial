#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector <int> dist (n, INT_MAX);
        vector <vector <pair <int, int>>> adj(n);

        for (int i = 0; i < flights.size(); i++) {

            int u = flights[i][0];
            int v = flights[i][1];
            int weight = flights[i][2];

            adj[u].push_back({weight, v});
        }

        queue < pair <int, pair <int, int>>> pq;
        dist[src] = 0;
        pq.push({-1, {0, src}});

        while (!pq.empty()) {

            int distance = pq.front().second.first;
            int node = pq.front().second.second;
            int stop = pq.front().first;
            pq.pop();
            
            if (stop >= k) continue;

            for (auto i : adj[node]) {
                int newnode = i.second;
                int weight = i.first;
                int currStop = stop + 1;
                if (dist[newnode] > distance + weight) {
                    dist[newnode] = distance + weight;
                    pq.push({ currStop,{dist[newnode], newnode}});
                }
            }
        }

        if (dist[dst] == INT_MAX) return -1;
        return dist[dst];
        
    }
};