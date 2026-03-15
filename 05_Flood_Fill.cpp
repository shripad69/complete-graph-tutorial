#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size(), m = image[0].size();
        int ori = image[sr][sc];

        if (ori == color) return image;
        queue <pair <int, int>> q;

        q.push({sr, sc});
        image[sr][sc] = color;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            pair <int, int> fr = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int ni = fr.first + dx[k];
                int nj = fr.second + dy[k];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && image[ni][nj] == ori) {
                    q.push({ni, nj});
                    image[ni][nj] = color;
                }
            }
        }

        return image;

    }
};