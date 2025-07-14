class Solution {
public:
    int bin_pow(int a, int b, int m) {
        int result = 1;
        while(b > 0) {
            if(b & 1) result = (result * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return result;
    }

    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        for(int i = 0; i < variables.size(); i++) {
            auto x = variables[i];
            int a = x[0], b = x[1], c = x[2], m = x[3];
            if(bin_pow(bin_pow(a, b, 10), c, m) == target) ans.push_back(i);
        }
        return ans;
    }
};
