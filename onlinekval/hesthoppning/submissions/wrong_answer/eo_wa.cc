#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>

using namespace std;

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

int main() {
    int N, M;
    cin >> N >> M;
    vector< vector<bool> > grid(N, vector<bool>(M, false));
    vector< vector<bool> > vis(N, vector<bool>(M, false));
    int hestPos[2][2];
    int hi = 0;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            char c = s[j];
            if (c == '#') {
                grid[i][j] = false;
            } else {
                grid[i][j] = true;
                if (c == 'H') {
                    hestPos[hi][0] = i;
                    hestPos[hi][1] = j;
                    hi++;
                }
            }
        }
    }
    deque< pair<int, int> > q;
    q.push_back(make_pair(hestPos[0][0], hestPos[0][1]));
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop_front();
        int r = p.first, c = p.second;
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr >= 0 && nr < N && nc >= 0 && nc < M && grid[nr][nc] && !vis[nr][nc]) {
                vis[nr][nc] = true;
                q.push_back(make_pair(nr, nc));
            }
        }
    }
    cout << (vis[hestPos[1][0]][hestPos[1][1]] ? "JA" : "NEJ") << endl;
    return 0;
}
