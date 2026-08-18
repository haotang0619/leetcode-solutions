class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0;
        while(numBottles >= numExchange) {
            ans += numExchange;
            numBottles = numBottles - numExchange + 1;
            numExchange++;
        }
        return ans + numBottles;
    }
};
