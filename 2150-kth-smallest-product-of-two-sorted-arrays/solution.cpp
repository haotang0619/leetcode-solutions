class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long l = -1e10, r = 1e10;
        vector<int> n1, p1, n2, p2;
        for(auto x: nums1) x < 0 ? n1.push_back(x) : p1.push_back(x);
        for(auto x: nums2) x < 0 ? n2.push_back(x) : p2.push_back(x);
        while(l < r) {
            long long m = l + (r - l) / 2;
            cout << l << " " << m << " " << r << endl;
            if(check(n1, n2, p1, p2, k, m)) r = m;
            else l = m + 1;
        }
        return l;
    }

private:
    bool check(vector<int>& n1, vector<int>& n2, vector<int>& p1, vector<int>& p2, long long k, long long m) {
        int i = n1.size() - 1, j = p2.size() - 1;
        long long cnt = 0;
        while(i >= 0 && j >= 0) {
            if((long long)n1[i] * p2[j] <= m){
                cnt += (i + 1);
                if(cnt >= k) return true;
                j--;
            } else i--;
        }
        i = n2.size() - 1, j = p1.size() - 1;
        while(i >= 0 && j >= 0) {
            if((long long)n2[i] * p1[j] <= m){
                cnt += (i + 1);
                if(cnt >= k) return true;
                j--;
            } else i--;
        }
        i = n1.size() - 1, j = 0;
        while(i >= 0 && j < n2.size()) {
            if((long long)n1[i] * n2[j] <= m){
                cnt += (n2.size() - j);
                if(cnt >= k) return true;
                i--;
            } else j++;
        }
        i = 0, j = p2.size() - 1;
        while(i < p1.size() && j >= 0) {
            if((long long)p1[i] * p2[j] <= m){
                cnt += (j + 1);
                if(cnt >= k) return true;
                i++;
            } else j--;
        }
        return false;
    }
};
