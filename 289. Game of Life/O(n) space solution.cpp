class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty() || board[0].empty())
            return ;
        int rN = board.size(), cN = board[0].size();
        vector<vector<int>> copy = board;
        vector<pair<int, int>> act{{-1,-1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}};
        for(int i=0; i<rN; ++i){
            for(int j=0; j<cN; ++j){
                int cnt = 0;
                for(auto& tmp : act){
                    int r = i+tmp.first, c = j+tmp.second;
                    if(0<=r && r<rN && 0<=c && c<cN && copy[r][c]==1)
                        ++cnt;
                }
                if(cnt<2 || cnt>3 || (board[i][j]==0 && cnt==2))
                    board[i][j] = 0;
                else
                    board[i][j] = 1;
            }
        }
    }
};
