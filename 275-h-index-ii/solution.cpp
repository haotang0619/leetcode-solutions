class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 1, r = n;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(citations[n - m - 1] <= m) r = m;
            else l = m + 1;
        }
        return l > 1 ? l : (citations.back() == 0 ? 0 : 1);
    }
};
