class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.empty())
            return nums;
        for(int p=nums.size()/2-1; p>=0; --p)
            adjust(nums, p, nums.size());
        for(int i=nums.size()-1; i>0; --i){
            std::swap(nums[0], nums[i]);
            adjust(nums, 0, i);
        }
        return nums;
    }

    void adjust(vector<int>& nums, int curr, int len){
        while(true){
            int pos = curr;
            if(2*curr+1<len && nums[2*curr+1]>nums[pos])
                pos = 2*curr+1;
            if(2*curr+2<len && nums[2*curr+2]>nums[pos])
                pos = 2*curr+2;
            if(pos==curr)
                break;
            std::swap(nums[pos], nums[curr]);
            curr = pos;
        }
    }
};
