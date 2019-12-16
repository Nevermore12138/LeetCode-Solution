class Solution {
public:
    string longestPalindrome(string s) {
        if(!s.size())
            return s;
        int maxLen = 1;
        int start = 0;
        for(int i=0; i<= s.size()-maxLen/2-1; ++i){
            int len1 = getPalindrome(s, i, i);
            int len2 = 0;
            if(s[i]==s[i+1])
                len2 = getPalindrome(s, i, i+1);
            int len = max(len1, len2);
            if(len>maxLen){
                start = i-(len-1)/2;
                maxLen = len;
            }    
        }
        return s.substr(start, maxLen);
    }

    int getPalindrome(const string& oriStr, int start, int end){
        while(start>=0 && end<=oriStr.size()-1 && oriStr[start]==oriStr[end]){
            start -= 1;
            end += 1;
        }
        return end-start-1;
    }
};
