class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> mp;
        for(auto& rec : rectangles) {
            int a = rec[0], b = rec[1], c = gcd(a, b);
            mp[{a / c, b / c}]++;
        }
        long long ans = 0;
        for(auto& [ratio, cnt] : mp) {
            if(cnt >= 2) ans += (long long)cnt * (cnt - 1) / 2;
        }
        return ans;
    }
};
