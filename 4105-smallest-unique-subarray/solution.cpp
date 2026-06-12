// Saw hints and learned the Rolling Hash
// Binary Search was figured out by myself    
class RollingHash {
public:
    using ull = unsigned long long;

    int n;
    ull BASE = 131;
    vector<ull> h, p;

    RollingHash(vector<int>& arr) {
        n = arr.size();
        h.assign(n + 1, 0);
        p.assign(n + 1, 1);
        for (int i = 0; i < n; i++) {
            h[i + 1] = h[i] * BASE + (arr[i] + 1);
            p[i + 1] = p[i] * BASE;
        }
    }

    ull getHash(int l, int r) {
        return h[r + 1] - h[l] * p[r - l + 1];
    }
};

class Solution {
public:
    bool checkUnique(RollingHash* rh, int k) {
        map<unsigned long long, int> mp;
        for(int i = 0; i < rh->n - k + 1; i++) mp[rh->getHash(i, i + k - 1)]++;
        for(auto &x : mp) {
            if(x.second == 1) return true;
        }
        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        RollingHash* rh = new RollingHash(nums);
        int l = 1, r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (checkUnique(rh, m)) r = m;
            else l = m + 1;
        }
        return l;
    }
};
