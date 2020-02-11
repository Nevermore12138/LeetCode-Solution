class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> emp;
        vector<vector<int>> res{emp};
        if(nums.empty())
            return res;
        vector<int> ele(nums.begin(), nums.begin()+1);
        res.push_back(ele);
        for(int i=1; i<nums.size(); ++i){
            vector<vector<int>> temp;
            vector<int> elePart(nums.begin(), nums.begin()+i+1);
            temp.push_back(elePart);
            for(vector<int> buf : res){
                if(buf.size()<i){
                    buf.push_back(nums[i]);
                    temp.push_back(buf);
                }
            }
            res.insert(res.end(), temp.begin(), temp.end());
        }
        return res;
    }
};
