class Solution {
private:
    unordered_map<int, int> hashMap;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> resMid;
        for(int element : nums) ++hashMap[element];
        for(const auto &p : hashMap) resMid.push_back(p.first);
        qSort(resMid, 0, resMid.size()-1);
        auto kEle = resMid.begin()+k;
        vector<int> res(resMid.begin(), kEle);
        return res;
    }

    void qSort(vector<int>& list, int low, int high){
        if(low<high){
            int pivot = partition(list, low, high);
            qSort(list, low, pivot-1);
            qSort(list, pivot+1, high);
        }
    }

    int partition(vector<int>& list, int low, int high){
        int pivotKey = hashMap[list[high]];
        int i = low;
        for(int j=low; j<list.size()-1; ++j){
            if(hashMap[list[j]]>pivotKey){
                swap(list, i, j);
                ++i;
            }
        }
        swap(list, i, high);
        return i;
    }

    void swap(vector<int>& list, int idx1, int idx2){
        int temp = list[idx1];
        list[idx1] = list[idx2];
        list[idx2] = temp;
    }
};
