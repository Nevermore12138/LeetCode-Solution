class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())
            return s;
        int end = s.size()-1;
        string res;
        while(end >=0){
            if(isspace(s[end])){
                --end;
                continue;
            }
            int beg = end;
            while(beg>=0 && !isspace(s[beg]))
                --beg;
            beg += 1;
            res += s.substr(beg, end-beg+1)+ " ";
            end = beg-2;
        }
        return res.substr(0, res.size()-1);
    }
};
