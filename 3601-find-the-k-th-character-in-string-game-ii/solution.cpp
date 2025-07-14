class Solution {
public:
    // Figured out by myself!
    char kthCharacter(long long k, vector<int>& operations) {
        vector<long long> v = {k};
        while(k > 1) {
            k = k - pow(2, ceil(log2(k) - 1));
            v.push_back(k);
        }
        reverse(v.begin(), v.end());
        char c = 'a';
        for(int i = 1; i < v.size(); i++) {
            int op = ceil(log2(v[i])) - 1;
            if(operations[op] == 1) c = c == 'z' ? 'a' : c + 1;
        }
        return c;
    }
};
