class Solution {
public:
    int prefixLen(string s1, string s2) {
        int cnt = 0;
        for(int i = 0; i < min(s1.size(), s2.size()); i++) {
            if(s1[i] == s2[i]) cnt++;
            else break;
        }
        return cnt;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        vector<string> v1, v2;
        for(auto x : arr1) v1.push_back(to_string(x));
        for(auto x : arr2) v2.push_back(to_string(x));
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        int i1 = 0, i2 = 0, ans = 0;
        do {
            ans = max(ans, prefixLen(v1[i1], v2[i2]));
            if(v1[i1] < v2[i2] && i1 + 1 < v1.size()) i1++;
            else i2++;
        } while(i1 < v1.size() && i2 < v2.size());
        return ans;
    }
};
