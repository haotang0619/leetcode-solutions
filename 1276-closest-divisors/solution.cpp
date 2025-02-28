class Solution {
public:
    vector<int> find2Ints(int n) {
        int start = (int)sqrt(n);
        for(int i = start; i >= 1; i--) {
            if(n % i == 0) return {i, n / i};
        }
        return {1, n};
    } 

    vector<int> closestDivisors(int num) {
        vector<int> v1 = find2Ints(num + 1);
        vector<int> v2 = find2Ints(num + 2);
        return (v1[1] - v1[0]) <= (v2[1] - v2[0]) ? v1 : v2;
    }
};
