class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> v;
        for(int i = 0; i < nums1.size(); i++) v.push_back({nums1[i], i});
        vector<long long> ans(v.size(), 0LL);
        sort(v.begin(), v.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        queue<int> buf;
        for(int i = 0; i < v.size(); i++) {
            pair<int, int> x = v[i];
            ans[x.second] = sum;
            buf.push(nums2[x.second]);
            if(i == v.size() - 1 || x.first < v[i + 1].first) {
                while(!buf.empty()) {
                    int b = buf.front();
                    buf.pop();
                    sum += b;
                    pq.push(b);
                    if(pq.size() > k) {
                        int t = pq.top();
                        sum -= t;
                        pq.pop();
                    }
                }
            }
        }
        return ans;
    }
};
