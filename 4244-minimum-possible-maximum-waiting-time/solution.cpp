class Solution {
public:
    int base = 131, mod = 1e9 + 7;
    int getHash(int& allowed, int& car, vector<int>& fuelLeft, vector<int>& occupiedUntil) {
        vector<int> v = {allowed, car, fuelLeft[0], fuelLeft[1], occupiedUntil[0], occupiedUntil[1]};
        long long hash = 0;
        for(auto& num : v) hash = (hash * base + num) % mod;
        return hash;
    }

    vector<int> traverse(pair<int, int>& best, unordered_map<int, vector<int>>& memo, vector<int>& demand, vector<int> fuelLeft, vector<int> occupiedUntil, int maxWait, int car, int allowed) {
        // Normalize
        if(fuelLeft[0] > fuelLeft[1]) {
            swap(fuelLeft[0], fuelLeft[1]);
            swap(occupiedUntil[0], occupiedUntil[1]);
        }

        // Memo
        int curr = getHash(allowed, car, fuelLeft, occupiedUntil);
        if(memo.contains(curr)) return memo[curr];

        // Leaf
        int n = demand.size();
        if(car == n || fuelLeft[0] < demand[car] && fuelLeft[1] < demand[car]) {
            if(best.first < car) {
                best.first = car, best.second = maxWait;
            } else if(best.first == car) {
                best.second = min(best.second, maxWait);
            }
            return memo[curr] = {car - 1, maxWait};
        }

        // Pruning
        int totalLeft = fuelLeft[0] + fuelLeft[1];
        int canFuelTo = car, demandNeed = 0;
        for(int i = car; i < n; i++) {
            demandNeed += demand[i];
            if(demandNeed > totalLeft) break;
            canFuelTo = i + 1;
        }
        if(canFuelTo < best.first) return memo[curr] = {car - 1, maxWait};
        if(canFuelTo == best.first && maxWait >= best.second) {
            return memo[curr] = {car - 1, maxWait};
        }

        // Traverse
        vector<vector<int>> res(2, {car - 1, maxWait});
        for(int i = 0; i < 2; i++) {
            if(fuelLeft[i] < demand[car]) continue;

            int start = max(allowed, occupiedUntil[i]);
            int wait = start - allowed;

            auto nextFuelLeft = fuelLeft;
            nextFuelLeft[i] -= demand[car];

            auto nextOccupiedUntil = occupiedUntil;
            nextOccupiedUntil[i] = start + demand[car];
            
            res[i] = traverse(best, memo, demand, nextFuelLeft, nextOccupiedUntil, max(maxWait, wait), car + 1, start);
        }
        
        // Pick the better one
        auto ans = res[0];
        if(res[0][0] < res[1][0] || res[0][0] == res[1][0] && res[0][1] > res[1][1]) {
            ans = res[1];
        }
        return memo[curr] = ans;
    }

    int minMaxWaitingTime(vector<int>& demand, vector<int>& fuel) {
        int n = demand.size();
        pair<int, int> best = {-1, INT_MAX};
        unordered_map<int, vector<int>> memo;
        return traverse(best, memo, demand, fuel, {0, 0}, -1, 0, 0)[1];
    }
};
