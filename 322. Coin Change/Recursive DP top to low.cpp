class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount<1)
            return 0;
        unordered_map<int, int> buff;
        return changeHelper(coins, amount, buff);
    }

    int changeHelper(vector<int>& coins, int amount, unordered_map<int, int>& mem){
        if(amount==0)
            return 0;
        if(amount < 0)
            return -1;
        if(mem.find(amount) != mem.end())
            return mem[amount];
        int minVal = INT_MAX;
        for(int i : coins){
            int res = changeHelper(coins, amount-i, mem);
            if(res>=0 && res<minVal)
                minVal = res;
        }
        int result = minVal==INT_MAX? -1:minVal+1;
        mem[amount] = result;
        return result;
    }
};
