class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        int len = grid.size();
        int wid = grid[0].size();
        int res = 0;
        stack<pair<int, int>> stk;
        for(int i=0; i<len; ++i){
            for(int j=0; j<wid; ++j){
                if(grid[i][j]=='1'){
                    grid[i][j]='0';
                    stk.push({i,j});
                    while(!stk.empty()){
                        int r = stk.top().first, c = stk.top().second;
                        stk.pop();
                        if(r-1>=0 && grid[r-1][c]=='1'){
                            grid[r-1][c]='0';
                            stk.push({r-1, c});
                        }
                        if(r+1<len && grid[r+1][c]=='1'){
                            grid[r+1][c]='0';
                            stk.push({r+1, c});
                        }
                        if(c-1>=0 && grid[r][c-1]=='1'){
                            grid[r][c-1]='0';
                            stk.push({r, c-1});
                        }
                        if(c+1<wid && grid[r][c+1]=='1'){
                            grid[r][c+1]='0';
                            stk.push({r, c+1});
                        }
                    }
                    ++res;
                }
            }      
        }
        return res;
    }
};
