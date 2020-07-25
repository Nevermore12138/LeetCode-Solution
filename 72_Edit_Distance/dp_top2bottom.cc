class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size()+1, vector<int>(word2.size()+1, -1));
        return helper(word1, word2, word1.size()-1, word2.size()-1, memo);
    }

    int helper(string& word1, string& word2, int idx1, int idx2, vector<vector<int>>& memo){
        if(idx1 < 0)
            return idx2+1;
        if(idx2 < 0)
            return idx1+1;
        if(word1[idx1] == word2[idx2]){
            if(memo[idx1][idx2] == -1)
                memo[idx1][idx2] = helper(word1, word2, idx1-1, idx2-1, memo);
            return memo[idx1][idx2];
        }
        // replace
        if(memo[idx1][idx2] == -1)
            memo[idx1][idx2] = helper(word1, word2, idx1-1, idx2-1, memo);
        int replace_val = memo[idx1][idx2]+1;
        // delete
        if(memo[idx1][idx2+1] == -1)
            memo[idx1][idx2+1] = helper(word1, word2, idx1-1, idx2, memo);
        int delete_val = memo[idx1][idx2+1]+1;
        // insert
        if(memo[idx1+1][idx2] == -1)
            memo[idx1+1][idx2] = helper(word1, word2, idx1, idx2-1, memo);
        int insert_val = memo[idx1+1][idx2]+1;
        return min(replace_val, min(delete_val, insert_val));
    }
};