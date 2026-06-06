class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long m = mass;
        sort(asteroids.begin(), asteroids.end());
        for(auto x : asteroids) {
            if(m < x) return false;
            m += x;
        }
        return true;
    }
};
