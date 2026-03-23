// The main idea is to perform a Depth First Search (DFS) on the Directed Acyclic Graph (DAG) and, for each vertex, push it onto a stack only after visiting all its adjacent vertices. This ensures that every vertex appears after all its neighboring vertices.
// Finally, reversing the stack (or popping elements from it) gives the topological ordering of the graph.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
    -------------------------------------------------------
    Function: dfs
    Purpose : Perform DFS traversal and store nodes
              in post-order for Topological Sort
    -------------------------------------------------------
    Parameters:
        node -> current node
        vis  -> visited array
        topo -> stores topological order (in reverse initially)
        adj  -> adjacency list
    -------------------------------------------------------
    */
    void dfs(int node, vector<int> &vis, vector<int> &topo, vector<vector<int>> &adj) {
        
        // Mark current node as visited
        vis[node] = 1;

        // Traverse all adjacent nodes
        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, vis, topo, adj);
            }
        }

        // Push node after visiting all its neighbors
        // (Post-order step -> important for topo sort)
        topo.push_back(node);
    }

    /*
    -------------------------------------------------------
    Function: topoSort
    Purpose : Returns Topological Ordering of a DAG
    -------------------------------------------------------
    Parameters:
        V     -> number of vertices
        edges -> list of directed edges
    -------------------------------------------------------
    Approach:
        1. Build adjacency list
        2. Perform DFS for all unvisited nodes
        3. Store nodes in post-order
        4. Reverse the result to get topo order
    -------------------------------------------------------
    Time Complexity  : O(V + E)
    Space Complexity : O(V + E)
    -------------------------------------------------------
    */
    vector<int> topoSort(int V, vector<vector<int>> &edges) {

        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        // Step 2: Initialize visited array
        vector<int> vis(V, 0);

        // Stores result (in reverse order initially)
        vector<int> topo;

        // Step 3: Run DFS for all components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, topo, adj);
            }
        }

        // Step 4: Reverse to get correct topological order
        reverse(topo.begin(), topo.end());

        return topo;
    }
};