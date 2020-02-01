class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> buff;
        int label1 = (nums.size()-1)/2;
        int label2 = nums.size()-1;
        for(int i=0; i<nums.size(); ++i){
            if(i%2==0)
                buff.push_back(nums[label1--]);
            else
                buff.push_back(nums[label2--]);
        }
        nums = buff;
    }
};
