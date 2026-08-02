class Solution {
public:
    bool check(int& num) {
        string s = to_string(num);
        for(auto& c : s) {
            if(c != '1') return false;
        }
        return true;
    }

    int smallestRepunitDivByK(int k) {
        int x = k % 10;
        if(x != 1 && x != 3 && x != 7 && x != 9) return -1;
        vector<int> v(10);
        for(int i = 0; i <= 9; i++) v[(x * i) % 10] = i;
        int prev = k * v[1];
        int ans = 0;
        while(!check(prev)) {
            ans++;
            prev /= 10;
            prev += (k * v[(11 - prev % 10) % 10]);
        }
        return ans + to_string(prev).size();
    }
};
