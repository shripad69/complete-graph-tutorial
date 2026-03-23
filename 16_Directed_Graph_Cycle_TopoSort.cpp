#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
    -------------------------------------------------------
    Function: isCyclic
    Purpose : Detect cycle in a Directed Graph
              using Topological Sort (BFS - Kahn's Algo)
    -------------------------------------------------------
    Parameters:
        V   -> number of vertices
        adj -> adjacency list
    -------------------------------------------------------
    Idea:
        - If graph has NO cycle → Topo sort includes all nodes
        - If graph has cycle    → Some nodes will never reach indegree 0
    -------------------------------------------------------
    Condition:
        topo_count != V → cycle exists
    -------------------------------------------------------
    Time Complexity  : O(V + E)
    Space Complexity : O(V)
    -------------------------------------------------------
    */

    bool isCyclic(int V, vector<vector<int>> &adj) {

        // Step 1: Compute indegree of each node
        vector<int> indegree(V, 0);
        for (int u = 0; u < V; u++) {
            for (auto v : adj[u]) {
                indegree[v]++;
            }
        }

        // Step 2: Push all nodes with indegree = 0 into queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Count of processed nodes
        int count = 0;

        // Step 3: BFS traversal (Kahn's Algorithm)
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            count++;  // node is processed

            // Reduce indegree of neighbors
            for (auto neighbor : adj[node]) {
                indegree[neighbor]--;

                // If indegree becomes 0, push to queue
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: Check for cycle
        // If not all nodes are processed → cycle exists
        return (count != V);
    }
};