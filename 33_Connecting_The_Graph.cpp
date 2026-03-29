#include <bits/stdc++.h>
using namespace std;


class DisjointSet {

    public : 
    vector <int> size, par;


    DisjointSet (int n ) {
        size.resize(n + 1, 1);
        par.resize(n + 1);

        for (int i = 0; i < n + 1; i++) {
            par[i] = i;
        }
    }

    int findUparent (int node) {
        if (node == par[node]) {
            return node;
        }

        return par[node] = findUparent(par[node]);
    }

    void unionBySize (int u, int v) {

        int up_u = findUparent(u);
        int up_v = findUparent(v);

        if (up_u == up_v) return ;

        if (size[up_u] < size[up_v]) {
            size[up_v] += size[up_u];
            par[up_u] = up_v;
        }
        else {
            size[up_u] += size[up_v];
            par[up_v] = up_u; 
        }
    }

};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {

        int components = 0, extraEdges = 0;
        DisjointSet ds = DisjointSet(n + 1);

        for (int i = 0; i < edge.size(); i++) {
            int u = edge[i][0];
            int v = edge[i][1];

            if (ds.findUparent(u) == ds.findUparent(v)) {
                extraEdges++;
            }
            else {
                ds.unionBySize(u, v);
            }
        }

        for (int i = 0; i < n; i++) {
            if (ds.par[i] == i) components++;
        }

        if (components - 1 <= extraEdges) {
            return components - 1;
        }

        return -1;
    }
};