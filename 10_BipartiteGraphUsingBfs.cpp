#include <bits/stdc++.h>
using namespace std;


// logic -->
    // odd length chi cycle asli ke bipartite nahiye
    // mhnun side che nodes la 0, 1 as colour krt chal and mg cycle asli and same colour asla tr falsee return kra

class Solution {
public:

    bool bfs (vector <int>& vis, vector <vector <int>>& graph, int node, int col, int par) {

        vis[node] = col;
        queue <pair <int, int>> q;
        q.push({node, -1});


        while (!q.empty()) {
            pair <int, int> i = q.front();
            q.pop();

            for (auto p : graph[i.first]) {
                // asun visit kela nahiy 
                if (vis[p] == -1) {

                    // color change krun insert kra  
                    vis[p] = 1 - vis[i.first];
                    q.push({p, i.first});
                }
                // side la ahe ani same color ahey
                else if (vis[p] == vis[i.first]) {
                    return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> vis (n , -1);

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                if (!bfs(vis, graph, i, 0, -1)) return false;
            }
        }
        return true;
    }
};