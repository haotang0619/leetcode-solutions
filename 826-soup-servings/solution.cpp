class Solution {
public:
    // Saw discussion
    map<pair<int, int>, double> mp;

    double prob(int a, int b) {
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1;
        if(b <= 0) return 0;
        if(mp.contains({a, b})) return mp[{a, b}];
        double p = 0.25 * (prob(a - 4, b) + prob(a - 3, b - 1) + prob(a - 2, b - 2) + prob(a - 1, b - 3));
        mp[{a, b}] = p;
        return p;
    }

    double soupServings(int n) {
        if(n >= 4801) return 1;
        int units = ceil((double)n / 25);
        return prob(units, units);
    }
};
