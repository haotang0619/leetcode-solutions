class Solution {
public:
    map<tuple<int, int, int>, int> memo; 
    
    int find(int root, int l, int r) {
        if(memo[{root, l, r}] != 0) return memo[{root, l, r}];
        if(l == r) return memo[{root, l, r}] = 1;
        int ansL = 0, ansR = 0;
        if(root == l) ansL = 1;
        else {
            for(int i = l; i < root; i++) ansL += find(i, l, root - 1);
        }
        if(root == r) ansR = 1;
        else {
            for(int i = root + 1; i <= r; i++) ansR += find(i, root + 1, r);
        }
        return memo[{root, l, r}] = ansL * ansR;
    }

    int numTrees(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) ans += find(i, 1, n);
        return ans;
    }
};
