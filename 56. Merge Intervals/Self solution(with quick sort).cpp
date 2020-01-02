class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return intervals;
        // qSort(intervals, 0, intervals.size()-1);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int handle = 0;
        while(handle<intervals.size()-1){
            if(intervals[handle+1][0]<=intervals[handle][1]){
                intervals[handle+1][0] = intervals[handle][0];
                intervals[handle+1][1] = max(intervals[handle][1], intervals[handle+1][1]);
                ++handle;
            }
            else{
                result.push_back(intervals[handle]);
                ++handle;
            }
        }
        result.push_back(intervals[handle]);
        return result;
    }

    void qSort(vector<vector<int>>& list, int low, int high){
        int pivot;
        if(low<high){
            pivot = partition(list, low, high);
            qSort(list, low, pivot-1);
            qSort(list, pivot+1, high);
        }
    }

    int partition(vector<vector<int>>& list, int low, int high){
        int pivotKey = list[high][0];
        int i = low;
        for(int j=low; j<high; ++j){
            if(list[j][0]<pivotKey){
                swap(list, i, j);
                ++i;
            }
        }
        swap(list, i, high);
        return i;
    }

    void swap(vector<vector<int>>& list, int index1, int index2){
        vector<int> temp = list[index1];
        list[index1] = list[index2];
        list[index2] = temp;
    }
};
