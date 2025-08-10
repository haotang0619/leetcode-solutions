class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        sort(flowers.begin(), flowers.end());
        vector<int> p(people.begin(), people.end());
        sort(p.begin(), p.end());
        unordered_map<int, int> cnt;
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        for(auto x : p) {
            while(i < flowers.size() && flowers[i][0] <= x) {
                pq.push(flowers[i++][1]);
            }
            while(!pq.empty() && pq.top() < x) pq.pop();
            cnt[x] = pq.size();
        }
        vector<int> ans;
        for(auto x : people) ans.push_back(cnt[x]);
        return ans;
    }
};
