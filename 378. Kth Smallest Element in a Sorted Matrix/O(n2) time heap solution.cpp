class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.empty() || matrix[0].empty())
            return -1;
        priority_queue<int, vector<int>> pri_q;
        int n = matrix.size();
        for(int i=1; i<=k; ++i)
            pri_q.push(matrix[(i-1)/n][i-((i-1)/n)*n-1]);
        for(int j=k+1; j<=n*n; ++j){
            if(matrix[(j-1)/n][j-((j-1)/n)*n-1] < pri_q.top()){
                pri_q.pop();
                pri_q.push(matrix[(j-1)/n][j-((j-1)/n)*n-1]);
            }
        }
        return pri_q.top();
    }
};
