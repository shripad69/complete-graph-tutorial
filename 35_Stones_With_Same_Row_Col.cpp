#include <bits/stdc++.h>
using namespace std;

class DisjointSet {

public: 
    vector<int> par, size;   // par[i] = parent, size[i] = size of component


    // Constructor → initialize DSU with n nodes
    DisjointSet(int n) {
        par.resize(n + 1);
        size.resize(n + 1);

        // Initially, each node is its own parent and size = 1
        for (int i = 0; i <= n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    // Find ultimate parent with path compression
    int findUPar(int node) {
        if (par[node] == node) 
            return node;

        // Compress path for faster future queries
        return par[node] = findUPar(par[node]);
    }

    // Union two sets using size (attach smaller set to larger set)
    void unionBySize(int u, int v) {
        
        int up_u = findUPar(u); // root of u
        int up_v = findUPar(v); // root of v

        // If already in same component → do nothing
        if (up_u == up_v) return;
        
        // Attach smaller component under larger component
        if (size[up_u] < size[up_v]) {
            par[up_u] = up_v;
            size[up_v] += size[up_u]; // update size
        }
        else {
            par[up_v] = up_u;
            size[up_u] += size[up_v]; // update size
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int maxRow = 0, maxCol = 0;
        int n = stones.size();

        for (int i = 0; i < n; i++) {
            maxRow = max(maxRow, stones[i][0]);
            maxCol = max(maxCol, stones[i][1]);
        }

        DisjointSet ds (maxRow + maxCol);

        for (int i = 0; i < n; i++) {
            int row = stones[i][0];
            int col = stones[i][1];
            int dsrow = row + col + 1;

            ds.unionBySize(row, dsrow);
        }

        int cnt = 0;

        for (int i = 0; i < ds.par.size(); i++) {
            if (ds.par[i] == i && ds.size[i] > 1) {
                cnt++;
            }
        }

        return n - cnt;

    }
};