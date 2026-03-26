#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {

        vector<int> dist(100000, 0);
        queue<pair<int, int>> q;

        q.push({start, 0});
        dist[start] = 1;

        while (!q.empty()) {
            int num = q.front().first;
            int moves = q.front().second;
            q.pop();

            if (num == end) return moves;

            for (int i = 0; i < arr.size(); i++) {
                int new_num = (num * arr[i]) % 100000;

                if (!dist[new_num]) {
                    dist[new_num] = 1;
                    q.push({new_num, moves + 1});
                }
            }
        }

        return -1;
    }
};