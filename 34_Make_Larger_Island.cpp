#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, componentSize;

    DisjointSet(int n) {
        parent.resize(n);
        componentSize.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]); // path compression
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (componentSize[pu] < componentSize[pv]) {
            parent[pu] = pv;
            componentSize[pv] += componentSize[pu];
        } else {
            parent[pv] = pu;
            componentSize[pu] += componentSize[pv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        auto node = [&](int i, int j) {
            return i * n + j;
        };

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        // Step 1: Build DSU for all 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;

                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1) {
                        ds.unionBySize(node(i, j), node(ni, nj));
                    }
                }
            }
        }

        int ans = 0;

        // Step 2: Try converting each 0 → 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    int root = ds.findUPar(node(i, j));
                    ans = max(ans, ds.componentSize[root]);
                    continue;
                }

                int currSize = 1;
                unordered_set<int> uniqueParents;

                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1) {
                        int parent = ds.findUPar(node(ni, nj));

                        if (uniqueParents.insert(parent).second) {
                            currSize += ds.componentSize[parent];
                        }
                    }
                }

                ans = max(ans, currSize);
            }
        }

        return ans;
    }
};