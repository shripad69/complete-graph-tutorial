#include <bits/stdc++.h>
using namespace std;

class DisjointSet {

private: 
    vector<int> par, rank;   // par[i] = parent of node i, rank[i] = approx tree height

public:
    // Constructor → initialize DSU with n nodes (0 to n)
    DisjointSet(int n) {
        par.resize(n + 1);
        rank.resize(n + 1, 0);

        // Initially, every node is its own parent (separate component)
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }

    // Find ultimate parent of a node with path compression
    int findUPar(int node) {
        // If node is its own parent → root found
        if (par[node] == node) 
            return node;

        // Path compression: directly attach node to root
        return par[node] = findUPar(par[node]);
    }

    // Union two sets using rank (attach smaller tree under larger)
    void unionByRank(int u, int v) {
        
        int up_u = findUPar(u); // ultimate parent of u
        int up_v = findUPar(v); // ultimate parent of v

        // If both belong to same set → no need to union
        if (up_u == up_v) return;
        
        // Attach smaller rank tree under larger rank tree
        if (rank[up_u] < rank[up_v]) {
            par[up_u] = up_v;
        }
        else if (rank[up_v] < rank[up_u]) {
            par[up_v] = up_u;
        }
        else {
            // If ranks are equal → attach any and increase rank
            par[up_v] = up_u;
            rank[up_u]++;
        }
    }
};