class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(), sides.end());
        int a = sides[0], b = sides[1], c = sides[2];
        if(a + b <= c) return {};
        vector<double> ans;
        ans.push_back(acos(double(b * b + c * c - a * a) / (2 * b * c)));
        ans.push_back(acos(double(a * a + c * c - b * b) / (2 * a * c)));
        ans.push_back(acos(double(a * a + b * b - c * c) / (2 * a * b)));
        for(auto &d : ans) d = d * 180.0 / acos(-1.0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
