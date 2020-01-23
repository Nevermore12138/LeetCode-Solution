#define MIN(a, b) a<b? a:b
#define MAX(a, b) a>b? a:b

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty() || matrix[matrix.size()-1][matrix[0].size()-1]<target)
            return false;
        int maxLen = MAX(matrix.size()-1, matrix[0].size()-1);
        int low = 0;
        int high = maxLen;
        int a, b, mid;
        while(low<=high){
            mid = low + (high-low)/2;
            a = MIN(mid, matrix.size()-1);
            b = MIN(mid, matrix[0].size()-1);
            if(matrix[a][b]<target)
                low = mid + 1;
            else if(matrix[a][b]>target)
                high = mid - 1;
            else
                return true;
        }
        if(matrix[a][b]<target)
            ++mid;
        for(int i=mid; i<=maxLen; ++i){
            a = MIN(i, matrix.size()-1);
            b = MIN(i, matrix[0].size()-1);
            if(a==i){
                low = 0;
                high = b;
                while(low<=high){
                    mid = low + (high-low)/2;
                    if(matrix[a][mid]<target)
                        low = mid + 1;
                    else if(matrix[a][mid]>target)
                        high = mid - 1;
                    else
                        return true;
                }
            }
            if(b==i){
                low = 0;
                high = a;
                while(low<=high){
                    mid = low + (high-low)/2;
                    if(matrix[mid][b]<target)
                        low = mid + 1;
                    else if(matrix[mid][b]>target)
                        high = mid - 1;
                    else
                        return true;
                }
            }
        }
        return false;
    }
};
