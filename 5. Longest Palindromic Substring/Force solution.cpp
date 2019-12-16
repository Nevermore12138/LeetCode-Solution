class Solution {
public:
    string longestPalindrome(string s) {
        if(!s.size())
            return s;
        unordered_map<int, int> palindStore;
        int maxLen = 1;
        for(int i=0; i<s.size()-maxLen; ++i){
            for(int j=i+maxLen; j<s.size(); ++j){
                if(judgePalindrome(s, i, j))
                {
                    maxLen = max(maxLen, j-i+1);
                    palindStore.insert({j-i+1, i});
                }
            }
        }
        return s.substr(palindStore[maxLen], maxLen);
    }

    bool judgePalindrome(const string& oriStr, int start, int end){
        while(start<=end){
            if(oriStr[start] != oriStr[end])
                return false;
            start += 1;
            end -= 1;
        }
        return true;
    }
};
