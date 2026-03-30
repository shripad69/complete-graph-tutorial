#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int time = 1;

    void dfs(int node, int parent, vector<int>& vt, vector<int>& lt,
             vector<int>& vis, vector<vector<int>>& adj,
             vector<vector<int>>& bridges) {

        vis[node] = 1;
        vt[node] = lt[node] = time++;

        for (auto i : adj[node]) {
            if (i == parent) continue;

            if (vis[i]) {
                
                lt[node] = min(lt[node], vt[i]);
            }
            else {
                dfs(i, node, vt, lt, vis, adj, bridges);

                lt[node] = min(lt[node], lt[i]);

                if (lt[i] > vt[node]) {
                    bridges.push_back({node, i});
                }
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);

        for (auto &e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<vector<int>> bridges;
        vector<int> vt(n, 0), lt(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vt, lt, vis, adj, bridges);
            }
        }

        return bridges;
    }
};