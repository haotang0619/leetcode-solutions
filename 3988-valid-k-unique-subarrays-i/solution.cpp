// Learned Mo's Algorithm from this
class Solution {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        int bcnt = max(1, (int)sqrt(n));
        vector<int> indices(q);
        iota(indices.begin(), indices.end(), 0);
        
        sort(indices.begin(), indices.end(), [&](auto& a, auto& b) {
            auto &qa = queries[a], &qb = queries[b];
            int ba = qa[0] / bcnt, bb = qb[0] / bcnt;
            if(ba != bb) return ba < bb;
            return (ba & 1) ? (qa[1] > qb[1]) : (qa[1] < qb[1]);
        });

        unordered_map<int, int> freq;
        int oddCnt = 0, distCnt = 0;
        auto update = [&](int i, int add) {
            if(freq[nums[i]] == 0) ++distCnt;
            freq[nums[i]] += add;
            if(freq[nums[i]] == 0) --distCnt;

            if(freq[nums[i]] & 1) ++oddCnt;
            else --oddCnt;
        };

        vector<bool> ans(q);
        int l = 0, r = -1;
        for(auto& idx : indices) {
            int ql = queries[idx][0], qr = queries[idx][1];
            while(r < qr) update(++r, 1);
            while(l > ql) update(--l, 1);
            while(r > qr) update(r--, -1);
            while(l < ql) update(l++, -1);
            ans[idx] = (oddCnt == 0) && (distCnt == k);
        }
        return ans;
    }
};
