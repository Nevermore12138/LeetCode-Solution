class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        vector<int> state(light.size()+1, 0);
        state[0] = 1;
        int ckBeg = 0, res = 0, edge = 0;
        for(int i=0; i<light.size(); ++i){
            edge = max(edge, light[i]);
            state[light[i]] = 1;
            bool flag = true;
            for(int j=ckBeg; j<=edge; ++j){
                if(state[j]==0){
                    flag = false;
                    break;
                }
                ++ckBeg;
            }
            if(flag)
                ++res;
        }
        return res;
    }
};
