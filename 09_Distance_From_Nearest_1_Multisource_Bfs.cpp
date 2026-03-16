#include <bits/stdc++.h>
using namespace std;



// logic :-

    // agodr j cell 0 ahet tyancha dist from itself zero kra and tyna multisouce bfs mdhe taka 
    // now j cells 1 tenacha intial distance mark as INT_MAX

    // ata multisource bfs traverse kra , jymula srvat agodr shotest distacnes mark hotil 
    // ani main traick jar koni agodr to distacne shotest mark kela asl tr pudhe tyana call deu nka ...

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();


        queue <pair < pair <int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                }
                else {
                    mat[i][j] = INT_MAX;
                }
            }
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {

            pair <pair <int, int>, int> fr = q.front();
            int ci = fr.first.first;
            int cj = fr.first.second;
            int dist = fr.second;
            q.pop();

            for (int k = 0; k < 4; k++) {

                int ni = ci + dx[k];
                int nj = cj + dy[k];

                if ( ni >= 0 && ni < n && nj >= 0 && nj < m && dist + 1 < mat[ni][nj]) {
                    mat[ni][nj] = dist + 1;
                    q.push({{ni, nj}, dist + 1});
                }
            }
        }

        return mat;

    }
};