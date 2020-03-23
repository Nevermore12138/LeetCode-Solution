class Solution {
private:
    int len = 0;
    int wid = 0;
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        len = grid.size();
        wid = grid[0].size();
        int res = 0;
        for(int i=0; i<len; ++i){
            for(int j=0; j<wid; ++j){
                if(grid[i][j]=='1'){
                    grid[i][j]='0';
                    dfs(grid, i, j);
                    ++res;
                }
            }      
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int r, int c){
        if(r-1>=0 && grid[r-1][c]=='1'){
            grid[r-1][c]='0';
            dfs(grid, r-1, c);
        }
        if(r+1<len && grid[r+1][c]=='1'){
            grid[r+1][c]='0';
            dfs(grid, r+1, c);
        }
        if(c-1>=0 && grid[r][c-1]=='1'){
            grid[r][c-1]='0';
            dfs(grid, r, c-1);
        }
        if(c+1<wid && grid[r][c+1]=='1'){
            grid[r][c+1]='0';
            dfs(grid, r, c+1);
        }
    }
};
