class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        int len = grid.size();
        int wid = grid[0].size();
        deque<pair<int, int>> q;
        int res=0;
        for(int i=0; i<len; ++i){
            for(int j=0; j<wid; ++j){
                if(grid[i][j]=='1'){
                    q.push_back({i,j});
                    grid[i][j]='0';
                    while(!q.empty()){
                        int r=q.front().first, c=q.front().second;
                        q.pop_front();
                        if(r-1>=0 && grid[r-1][c]=='1'){
                            q.push_back({r-1, c});
                            grid[r-1][c]='0';
                        }
                        if(r+1<len && grid[r+1][c]=='1'){
                            q.push_back({r+1, c});
                            grid[r+1][c]='0';
                        }
                        if(c-1>=0 && grid[r][c-1]=='1'){
                            q.push_back({r, c-1});
                            grid[r][c-1]='0';
                        }
                        if(c+1<wid && grid[r][c+1]=='1'){
                            q.push_back({r, c+1});
                            grid[r][c+1]='0';
                        }
                    }
                    ++res;
                }
            }
        }
        return res;
    }
};
