class RangeFreqQuery {
public:
    int n;
    vector<pair<int, int>> v;

    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        v.resize(n);
        for(int i = 0; i < n; i++) v[i] = {arr[i], i};
        sort(v.begin(), v.end());
    }
    
    int query(int left, int right, int value) {
        int idx1 = lower_bound(v.begin(), v.end(), make_pair(value, left)) - v.begin();
        int idx2 = upper_bound(v.begin(), v.end(), make_pair(value, right)) - v.begin() - 1;
        if(idx1 == n) return 0;
        if(v[idx1].first != value) return 0;
        return idx2 - idx1 + 1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
