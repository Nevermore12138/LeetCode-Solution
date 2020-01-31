class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int> rec(nums.size(), 1);
        int res = 1;
        for(int i=0; i<nums.size(); ++i){
            for(int j=0; j<i; ++j){
                if(nums[j]<nums[i])
                    rec[i] = max(rec[i], rec[j]+1);
            }
            res = max(rec[i], res);
        }
        return res;
    }
};
