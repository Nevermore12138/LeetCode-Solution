class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // unordered_map<char, int> chMap;
        vector<int> chMap(128);
        for(char ch : s1)
            ++chMap[ch];
        int cnt = 0, left=0, n1=s1.size(), n2 = s2.size();
        for(int i=0; i<n2; ++i){
            if(--chMap[s2[i]]>=0){
                ++cnt;
                if(cnt == n1)
                    return true;
            }
            else{
                cnt = max(0, cnt-1);
                ++chMap[s2[i]];
                if(left<i){
                    ++chMap[s2[left]];
                    --i;
                }
                ++left;
            } 
        }
        return false;
    }
};
