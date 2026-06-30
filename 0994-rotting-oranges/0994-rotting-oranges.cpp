class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minutes = 0;
        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        queue<tuple<int,int,int>>q;
        int fresh = 0;
        for (int i=0; i < m; i++) {
            for (int j=0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i,j,0});
                }
                else if (grid[i][j] == 1) {
                    fresh += 1;
                }
            } 
        }
        while (!q.empty()) {
            auto [x,y, t] = q.front();
            q.pop();
            //minutes = max(t,minutes);
            minutes = t;
            for (auto [dx, dy] : directions) {
                int nx = x+dx;
                int ny = y+dy;
                if (0<=nx && nx < m && 0<=ny && ny <n && grid[nx][ny] == 1) {
                    fresh -= 1;
                    grid[nx][ny] = 2;
                    q.push({nx,ny,t+1});
                }
            }
        }
        return fresh == 0 ? (minutes): (-1);
    }
};