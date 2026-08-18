class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(), enemyEnergies.end());
        if(enemyEnergies[0] > currentEnergy) return 0;
        long long sum = accumulate(enemyEnergies.begin() + 1, enemyEnergies.end(), 0LL) + currentEnergy;
        return sum / enemyEnergies[0];
    }
};
