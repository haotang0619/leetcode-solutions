class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        long long sum = 0;
        if(n == 1) return target[0] == 1;
        priority_queue<long long> pq;
        for(auto &t : target) sum += t, pq.push(t);
        while(pq.top() != 1) {
            long long top = pq.top();
            pq.pop();
            long long rest = sum - top;
            long long original = top - rest;
            if(original < 1) return false;
            long long nextTop = pq.top();
            if(original > nextTop) {
                long long mul = (original - nextTop) / rest;
                original -= mul * rest;
            }
            pq.push(original);
            sum = sum - top + original;
        }
        return true;
    }
};
