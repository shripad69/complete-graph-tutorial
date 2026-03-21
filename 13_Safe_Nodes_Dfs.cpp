#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    

    bool dfs (int node, vector <int>& vis, vector <int>&path, vector <int>& unsafe, vector <vector <int>>& graph) {

        int n = graph.size();
        vis[node] = 1;
        path[node] = 1;


        for (auto i : graph[node]) {

            if (!vis[i]) {
                if (dfs(i, vis, path, unsafe, graph)){
                    unsafe[node] = 1;
                    path[node] = 0;
                    return true;
                }
                
            }
            else if (path[i] || unsafe[i]) {
                unsafe[node] = 1;
                path[node] = 0;
                return true;
            }
        }

        path[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector <int> vis(n, 0), path(n, 0), unsafe(n, 0);

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                dfs(i, vis, path, unsafe, graph);
            }
        }

        vector <int> safenodes;
        for (int i = 0; i < n; i++) {
            if (!unsafe[i]) safenodes.push_back(i);
        }
        return safenodes;
        
    }
};