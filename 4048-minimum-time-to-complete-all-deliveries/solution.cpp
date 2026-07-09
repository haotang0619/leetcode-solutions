class Solution {
public:
    bool check(vector<int>& del, vector<int>& rec, long long m) {
        int lcm = rec[0] * rec[1] / gcd(rec[0], rec[1]);
        long long slotA = m / rec[1] - m / lcm, slotB = m / rec[0] - m / lcm;
        long long leftA = max((long long)del[0] - slotA, 0LL), leftB = max((long long)del[1] - slotB, 0LL);
        long long slotShared = m - m / rec[0] - m / rec[1] + m / lcm;
        return slotShared >= leftA + leftB;
    }

    long long minimumTime(vector<int>& del, vector<int>& rec) {
        long long l = 2, r = 4e9 - 1;
        while(l < r) {
            long long m = l + (r - l) / 2;
            if(check(del, rec, m)) r = m;
            else l = m + 1;
        }
        return l;
    }
};
