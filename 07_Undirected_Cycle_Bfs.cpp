#include <bits/stdc++.h>
using namespace std;



// logic is -----
    // ek node la connect asleya srv node la visit kr and tyya srv nodes cha parent current node declear kra 
    
    // imp condition :-
    // jar ek node agodr visit zaleli  ani ti parent nahiy current node chi
    // mg off course tila kon tri dusrya ne mark kelay ani hence cycle ahe ethe  

class Solution {
  public:
  
  
  
    bool bfs (vector <int>& vis, vector <int>& parent, int j, vector <vector <int>>& adj) {
        
        queue <int> q;
        q.push(j);
        vis[j] = 1;
        
        while (!q.empty()) {
            int fr = q.front();
            q.pop();
            
            for (auto i : adj[fr]) {
                if (!vis[i] ) {
                    parent[i] = fr;
                    vis[i] = 1;
                    q.push(i);
                }

                // ti node visted ahe ani ani ti currnet node chi parent nahiy 
                else if (parent[fr] != i) {
                    return true;
                }
            }
        }
        
        return false;
        
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        
        vector <int> parent(V, -1);
        vector <int> vis(V, 0);
        vector <vector <int>> adj(V);
        
       for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        for (int i = 0; i < V; i++) {
            
            if (!vis[i]) {
                if (bfs(vis, parent, i, adj)) return true;
            }
        }
        return false;
        
       
    }
};