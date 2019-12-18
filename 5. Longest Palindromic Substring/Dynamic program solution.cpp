class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())
            return s;
        int maxLen = 1;
        int sunStrBeg = 0;
        bool stateJudge[s.size()][s.size()]={false};
        for(int end=0; end<= s.size()-1; ++end){
            stateJudge[end][end] = true;
            for(int start=0; start<end; ++start){
                if(s[start]==s[end] && (end-start<2 || stateJudge[start+1][end-1])){
                    stateJudge[start][end] = true;
                    if(end-start+1>maxLen){
                        sunStrBeg = start;
                        maxLen = end-start+1;
                    }
                }      
            }
        }
        return s.substr(sunStrBeg, maxLen);
    }
};
