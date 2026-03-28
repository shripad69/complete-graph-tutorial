#include <bits/stdc++.h>
using namespace std;

class DisjointSet {

    private: 
    vector <int> par, rank;


    public :
    DisjointSet(int  n) {
        par.resize (n + 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i < n + 1; i++) {
            par[i] = i;
        }
    }

    int findUPar (int node) {
        if (par[node] == node) 
            return node;

        return par[node] = findUPar(par[node]);
    }

    void unionByRank (int u, int v) {
        
        int up_u = findUPar(u);
        int up_v = findUPar(v);

        if (up_u == up_v) return;
        
        if (rank[up_u] < rank[up_v]) {
            par[up_u] = up_v;
        }
        else if (rank[up_u] > rank[up_v]) {
            par[up_v] = up_u;
        }
        else {
            par[up_v] = up_u;
            rank[up_u]++;
        }
    }

};

