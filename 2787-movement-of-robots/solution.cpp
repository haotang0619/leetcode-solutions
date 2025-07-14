class Solution {
public:
    int mod = 1e9 + 7;

    // Saw discussion
    int sumDistance(vector<int>& nums, string s, int d) {
        vector<long long> v;
        for(int i = 0; i < nums.size(); i++) {
            v.push_back((long long)nums[i] + d * (s[i] == 'L' ? -1 : 1));
        }
        sort(v.begin(), v.end());
        unsigned long long ans = 0;
        for(int i = 0, j = -v.size() + 1; i < v.size(); i++, j++) {
            ans = ans + (i + j) * v[i];
        }
        return (int)(ans % mod);
    }
};
