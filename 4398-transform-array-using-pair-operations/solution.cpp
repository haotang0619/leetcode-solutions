class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        int n = source.size();
        for(int i = 0; i < n - 1; i++) {
            long long delta = (long long)source[i] + source[i + 1] - target[i];
            if(delta > INT_MAX || delta < INT_MIN) return false;
            source[i] = target[i], source[i + 1] = delta;
        }
        return source[n - 1] == target[n - 1];
    }
};
