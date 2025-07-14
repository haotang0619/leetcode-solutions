/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        char dir = 'R';
        int l = 0, r = n - 1, t = 1, d = m - 1;
        int i = 0, j = 0, cnt = 0;
        vector<vector<int>> ans(m, vector<int>(n, -1));
        while(cnt < m * n) {
            int now = head == nullptr ? -1 : head->val;
            head = head == nullptr ? head : head->next;
            ans[i][j] = now;
            cnt++;
            if(dir == 'R') {
                if(j < r) j++;
                else {
                    r--;
                    i++;
                    dir = 'D';
                }
            } else if(dir == 'D') {
                if(i < d) i++;
                else {
                    d--;
                    j--;
                    dir = 'L';
                }
            } else if(dir == 'L') {
                if(j > l) j--;
                else {
                    l++;
                    i--;
                    dir = 'U';
                }
            } else {
                if(i > t) i--;
                else {
                    t++;
                    j++;
                    dir = 'R';
                }
            }
        }
        return ans;
    }
};
