class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        while(n != 1) {
            int m = n;
            int sum = 0;
            while(m > 0) {
                sum += (m % 10) * (m % 10);
                m = m / 10;
            }
            if(st.find(sum) != st.end()) return false;
            st.insert(sum);
            n = sum;
        }
        return true;
    }
};
