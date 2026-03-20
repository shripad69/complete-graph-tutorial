#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main () {

    ll n, m;
    cin >> n >> m;


    // adj1 list each index is a node and corresponding vector represent the connected nodes to it 
    vector <vector <ll>> adj1(n);
    vector <vector <ll>> adj2(n, vector <ll> (n, 0));
    for (ll i = 0; i < m; i++) {
        ll u , v;
        cin >> u >>  v;

        // push other node into list of this node 
        adj1[u].push_back(v);
        adj1[v].push_back(u);

        // make edge by adding one to that cell
        adj2[v][u] = 1;
        adj2[u][v] = 1;
    }

    // printing adj1 
    for (ll i = 0; i < n; i++) {

        cout << i << " - ";
        for (ll j = 0; j < adj1[i].size(); j++) {
            cout << adj1[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;
    // printing adj2 
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j  < n; j++) {
            cout << adj2[i][j] << " ";
        }
        cout << endl;
    }
}