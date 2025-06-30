class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int p = 0;
        for(auto x : fruits) {
            for(int i = 0; i < baskets.size(); i++) {
                if(x <= baskets[i]) {
                    p++;
                    baskets[i] = 0;
                    break;
                }
            }
        }
        return fruits.size() - p;
    }
};
