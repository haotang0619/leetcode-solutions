class Solution {
public:
    int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        stack<tuple<int, int, int>> sk; // [number, contribution, index]
        int ans = 0, n = arr.size(), sumInStack = 0;
        for(int i = 0; i < n; i++) {
            while(!sk.empty() && get<0>(sk.top()) >= arr[i]) {
                sumInStack = (sumInStack - get<1>(sk.top())) % mod;
                sk.pop();
            }
            int prev = sk.empty() ? -1 : get<2>(sk.top());
            int contribution = arr[i] * (i - prev);
            sk.push({arr[i], contribution, i});
            sumInStack = (sumInStack + contribution) % mod;
            ans = (ans + sumInStack) % mod;
        }
        return ans;
    }
};
