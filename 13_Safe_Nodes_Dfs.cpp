#include <bits/stdc++.h>
using namespace std;




class Solution {
public:

    bool dfs(int node, vector<int>& vis, vector<int>& path,
             vector<vector<int>>& graph, vector<int>& unsafe) {

        vis[node] = 1;
        path[node] = 1;

        for (int nei : graph[node]) {

            // Case 1: not visited → explore
            // ek pn unsafe ghavli tr current node la unsafe kr and true return kr vrti
            if (!vis[nei]) {
                if (dfs(nei, vis, path, graph, unsafe)) {
                    unsafe[node] = 1;   // current becomes unsafe
                    path[node] = 0;
                    return true;
                }
            }

            // Case 2: back-edge → cycle
            // cycle ghavli tr current la unsafe kra ani true return kr vr
            else if (path[nei]) {
                unsafe[node] = 1;   // current in cycle → unsafe
                path[node] = 0;
                return true;
            }


            // imp ---------->
            
            // Case 3: already known unsafe
            // jr koni already unsafe ahe and tula connected ahe tr mg tu pn unsafe
            else if (unsafe[nei]) {
                unsafe[node] = 1;   // leads to unsafe → unsafe
                path[node] = 0;
                return true;
            }
        }

        path[node] = 0;  // backtrack
        return false;    // safe node
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> vis(n, 0);
        vector<int> path(n, 0);
        vector<int> unsafe(n, 0);  // 1 = unsafe, 0 = safe

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, path, graph, unsafe);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!unsafe[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};