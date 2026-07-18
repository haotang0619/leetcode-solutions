class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> avail;
        long long ans = 1;
        for(auto& t : tasks) {
            if(avail.contains(t)) ans = max(ans, avail[t]);
            ans++, avail[t] = ans + space;
        }
        return ans - 1;
    }
};
