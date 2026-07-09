class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> ind1, ind2;
        int n = s.size(), n1 = a.size(), n2 = b.size();
        for(int i = 0; i <= n - n1; i++) {
            if(s.substr(i, n1) == a) ind1.push_back(i);
        }
        for(int i = 0; i <= n - n2; i++) {
            if(s.substr(i, n2) == b) ind2.push_back(i);
        }
        if(ind2.size() == 0) return {};
        vector<int> ans;
        for(int i = 0, j = 0; i < ind1.size(); i++) {
            while(j < ind2.size() && ind1[i] - k > ind2[j]) j++;
            if(j < ind2.size()) {
               if(ind1[i] + k >= ind2[j]) ans.push_back(ind1[i]);
            } else break;
        }
        return ans;
    }
};
