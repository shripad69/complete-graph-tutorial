#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
    -------------------------------------------------------
    Function: topoSort (Kahn's Algorithm - BFS)
    Purpose : Returns Topological Ordering of a DAG
    -------------------------------------------------------
    Parameters:
        V     -> number of vertices
        edges -> list of directed edges
    -------------------------------------------------------
    Approach:
        1. Build adjacency list
        2. Compute indegree of each node
        3. Push all nodes with indegree = 0 into queue
        4. Process nodes using BFS
           - Remove node from queue
           - Add to topo order
           - Reduce indegree of neighbors
           - Push neighbor if indegree becomes 0
    -------------------------------------------------------
    Time Complexity  : O(V + E)
    Space Complexity : O(V + E)
    -------------------------------------------------------
    */

    vector<int> topoSort(int V, vector<vector<int>>& edges) {

        // Step 1: Adjacency list representation
        vector<vector<int>> adj(V);

        // Step 2: Indegree array initialization
        vector<int> indegree(V, 0);

        // Build graph and compute indegree
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);  // u → v
            indegree[v]++;        // increase indegree of v
        }

        // Step 3: Initialize queue with nodes having indegree = 0
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Stores final topological order
        vector<int> topo;

        // Step 4: BFS processing
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            // Add current node to topo order
            topo.push_back(node);

            // Traverse neighbors
            for (auto neighbor : adj[node]) {

                // Reduce indegree
                indegree[neighbor]--;

                // If indegree becomes 0, push to queue
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Optional: Cycle check
        // If topo size != V → cycle exists
        // (Topological sort only valid for DAG)
        // if (topo.size() != V) return {};

        return topo;
    }
};