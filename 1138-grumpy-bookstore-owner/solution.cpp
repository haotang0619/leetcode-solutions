class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0, happy = 0, n = customers.size();
        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 0) happy += customers[i];
        }
        int improve = 0;
        for(int i = 0, j = 0; j < n; j++) {
            if(grumpy[j] == 1) improve += customers[j];
            if(j - i >= minutes) {
                if(grumpy[i] == 1) improve -= customers[i];
                i++;
            }
            ans = max(ans, happy + improve);
        }
        return ans;
    }
};
