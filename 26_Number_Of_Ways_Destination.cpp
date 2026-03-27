#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector <vector < pair <int, int>>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            int node1 = roads[i][0];
            int node2 = roads[i][1];
            int dist = roads[i][2];

            adj[node1].push_back({dist, node2});
            adj[node2].push_back({dist, node1});
        }

        vector <int> dist (n,  INT_MAX), ways(n, 0);
        dist[0] = 0;
        dist[0] = 1;

        priority_queue<pair <int, int>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {

            int node = pq.top().second;
            int weight = pq.top().first;
            pq.pop();

            for (auto i : adj[node]) {
                if (dist[i.second] > weight + i.first) {
                    dist[i.second] = weight + i.first;
                    ways[i.second] = ways[node];
                    pq.push({dist[i.second], i.second});
                }
                else if (dist[i.second] > weight + i.first) {
                    ways[i.second] += ways[node];
                    pq.push({dist[i.second], i.second});
                }
            }
        }


        return ways[n - 1];
    }
};