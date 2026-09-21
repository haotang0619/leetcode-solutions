class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        auto check = [&](int r, int c) {
            for(auto& x : vector<int>({r, c})) {
                if(x < 1 || x > 8) return false;
            }
            return r == e && c == f;
        };

        // Rook
        for(int i = 1; i <= 8; i++) {
            if(b != d || (i - a) * (c - a) < 0 || abs(i - a) < abs(c - a)) {
                if(check(i, b)) return 1;
            }
            if(a != c || (i - b) * (d - b) < 0 || abs(i - b) < abs(d - b)) {
                if(check(a, i)) return 1;
            }
        }

        // Bishop
        for(int i = 1; i <= 7; i++) {
            int diff1 = a - c, diff2 = b - d;
            if(diff1 != diff2 || diff1 > 0 || abs(diff1) > i) {
                if(check(c - i, d - i)) return 1;
            }
            if(diff1 != -diff2 || diff1 > 0 || abs(diff1) > i) {
                if(check(c - i, d + i)) return 1;
            }
            if(diff1 != -diff2 || diff1 < 0 || abs(diff1) > i) {
                if(check(c + i, d - i)) return 1;
            }
            if(diff1 != diff2 || diff1 < 0 || abs(diff1) > i) {
                if(check(c + i, d + i)) return 1;
            }
        }
        
        return 2;
    }
};
