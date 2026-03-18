#include <bits/stdc++.h>
using namespace std;

/*
    LOGIC:
    --------
    - A graph is bipartite if we can color it using 2 colors (0 and 1)
      such that no two adjacent nodes have the same color.

    - If an odd length cycle exists → NOT bipartite

    APPROACH (BFS):
    ----------------
    - Start from a node, assign color 0
    - Push into queue
    - For every neighbor:
        → If unvisited → assign opposite color and push
        → If already visited and same color → return false
*/

class Solution {
public:

    /*
        BFS Function:
        -------------
        vis   → stores color (-1 = unvisited, 0/1 = colored)
        graph → adjacency list
        node  → starting node
    */
    bool bfs(vector<int>& vis, vector<vector<int>>& graph, int node) {

        queue<int> q;

        // Start with color 0
        vis[node] = 0;
        q.push(node);

        while (!q.empty()) {

            int curr = q.front();
            q.pop();

            // Traverse all neighbors
            for (auto nei : graph[curr]) {

                // If not visited → assign opposite color
                if (vis[nei] == -1) {
                    vis[nei] = 1 - vis[curr];
                    q.push(nei);
                }
                // If visited and same color → NOT bipartite
                else if (vis[nei] == vis[curr]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> vis(n, -1);  // -1 = unvisited

        // Handle disconnected components
        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                if (!bfs(vis, graph, i))
                    return false;
            }
        }

        return true;
    }
};