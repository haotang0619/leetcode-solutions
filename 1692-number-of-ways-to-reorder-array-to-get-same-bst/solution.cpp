class Solution {
public:
    struct Node {
        int val;
        Node *left = nullptr, *right = nullptr;
        Node(int v) : val(v) {}
    };

    int mod = 1e9 + 7;
    int numOfWays(vector<int>& nums) {
        Node *root = new Node(nums[0]);
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            int val = nums[i];
            Node *now = root;
            while(true) {
                if(val < now->val) {
                    if(now->left == nullptr) {
                        now->left = new Node(val);
                        break;
                    } else now = now->left;
                } else {
                    if(now->right == nullptr) {
                        now->right = new Node(val);
                        break;
                    } else now = now->right;
                }
            }
        }

        using ll = long long;
        auto fastPow = [&](ll a, int b) {
            ll res = 1;
            while(b) {
                if(b & 1) res = res * a % mod;
                a = a * a % mod, b >>= 1;
            }
            return res;
        };

        auto comb = [&](int n, int m) {
            ll res = 1;
            for(int i = 1; i <= m; i++) {
                res = res * (n - i + 1) % mod;
                res = res * fastPow(i, mod - 2) % mod;
            }
            return res;
        };

        using p2ll = pair<ll, ll>; // [ways, nodes count]
        auto traverse = [&](auto&& self, Node* now) -> p2ll {
            if(now == nullptr) return {1, 0};
            auto [ways1, cnt1] = self(self, now->left);
            auto [ways2, cnt2] = self(self, now->right);
            return {ways1 * ways2 % mod * comb(cnt1 + cnt2, min(cnt1, cnt2)) % mod, cnt1 + cnt2 + 1};
        };
        int ans = traverse(traverse, root).first - 1;
        return ans < 0 ? ans + mod : ans;
    }
};
