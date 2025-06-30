class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = 1e14;
        while(left < right) {
            long long mid = left + (right - left) / 2;
            if(check(ranks, cars, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }

private:
    bool check(vector<int>& ranks, int cars, long long m) {
        for(auto r : ranks) {
            cars -= (int)(sqrt((double)m / r));
            if(cars <= 0) return true;
        }
        return false;
    }
};
