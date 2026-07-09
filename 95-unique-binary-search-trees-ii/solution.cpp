/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(vector<int>& tree, int idx) {
        if(idx >= tree.size()) return nullptr;
        if(tree[idx] == 0) return nullptr;
        TreeNode* root = new TreeNode(tree[idx]);
        root->left = build(tree, idx * 2 + 1);
        root->right = build(tree, idx * 2 + 2);
        return root;
    }

    map<tuple<int, int, int>, vector<vector<int>>> memo;
    vector<vector<int>> findTrees(int root, int l, int r) {
        if(memo.contains({root, l, r})) return memo[{root, l, r}];
        if(l == r) return memo[{root, l, r}] = {{l}};
        vector<vector<int>> trees, treesL, treesR;
        
        if(root == l) treesL.push_back({});
        else {
            for(int i = l; i < root; i++) {
                vector<vector<int>> tmp = findTrees(i, l, root - 1);
                treesL.insert(treesL.end(), tmp.begin(), tmp.end());
            }
        }
        
        if(root == r) treesR.push_back({});
        else {
            for(int i = root + 1; i <= r; i++) {
                vector<vector<int>> tmp = findTrees(i, root + 1, r);
                treesR.insert(treesR.end(), tmp.begin(), tmp.end());
            }
        }
        
        int gap = r - l + 1, tot = pow(2, gap) - 1;
        for(auto& tl : treesL) {
            for(auto& tr : treesR) {
                vector<int> tree(tot, 0);
                tree[0] = root;
                for(int i = 1; i <= 2; i++) {
                    auto& t = (i == 1 ? tl : tr);
                    if(t.size() == 0) continue;
                    queue<pair<int, int>> qu; // [tl idx, tree idx]
                    qu.push({0, i});
                    while(!qu.empty()) {
                        auto [i1, i2] = qu.front();
                        qu.pop();
                        tree[i2] = t[i1];
                        if(i1 * 2 + 1 >= t.size()) continue;
                        if(t[i1 * 2 + 1] > 0) qu.push({i1 * 2 + 1, i2 * 2 + 1});
                        if(t[i1 * 2 + 2] > 0) qu.push({i1 * 2 + 2, i2 * 2 + 2});
                    }
                }
                trees.push_back(tree);
            }
        }
        return memo[{root, l, r}] = trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<vector<int>> trees;
        for(int i = 1; i <= n; i++) {
            vector<vector<int>> tmp = findTrees(i, 1, n);
            trees.insert(trees.end(), tmp.begin(), tmp.end());
        }
        vector<TreeNode*> ans;
        for(auto& tree : trees) ans.push_back(build(tree, 0));
        return ans;
    }
};
