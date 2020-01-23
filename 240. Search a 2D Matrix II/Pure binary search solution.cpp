#define MIN(a, b) a<b? a:b

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        return helpSearch(matrix, target, 0, 0);
    }

    bool helpSearch(vector<vector<int>>& matrix, int target, int row, int column){
        if(row==matrix.size() && column ==matrix[0].size())
            return false;
        row = MIN(row, matrix.size()-1);
        column = MIN(column, matrix[0].size()-1);
        int low = column;
        int high = matrix[0].size()-1;
        int mid;
        while(low<=high){
            mid = low + (high-low)/2;
            if(matrix[row][mid]<target)
                low = mid + 1;
            else if(matrix[row][mid]>target)
                high = mid - 1;
            else
                return true;
        }
        low = row + 1;
        high = matrix.size()-1;
        while(low<=high){
            mid = low + (high-low)/2;
            if(matrix[mid][column]<target)
                low = mid + 1;
            else if(matrix[mid][column]>target)
                high = mid - 1;
            else
                return true;
        }
        return helpSearch(matrix, target, row+1, column+1);
    }
};
