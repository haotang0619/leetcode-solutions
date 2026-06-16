// Asked GPT
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // 1. Check if solvable by counting inversions.
        //    The width is odd, so the inversion count must be even.
        int invCnt = 0;
        string s;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) s += board[i][j] + '0';
        }
        for(int i = 0; i < 6; i++) {
            if(s[i] == '0') continue;
            for(int j = i + 1; j < 6; j++) {
                if(s[j] == '0') continue;
                if(s[i] > s[j]) invCnt++;
            }
        }
        if(invCnt % 2 == 1) return -1;
        
        // 2. Check the minimum steps by using BFS
        //    Build the edges by checking all possibilities from the current state.
        int ans;
        unordered_set<string> vis;
        queue<pair<string, int>> q;
        q.push({s, 0});
        vis.insert(s);
        while(!q.empty()) {
            auto [front, step] = q.front();
            q.pop();
            if(front == "123450") {
                ans = step;
                break;
            }
            int idx = 0;
            for(int i = 0; i < 6; i++) {
                if(front[i] == '0') {
                    idx = i;
                    break;
                }
            }
            string s1 = front, s2 = front, s3 = front;
            if(idx == 0) {
                swap(s1[0], s1[1]);
                swap(s2[0], s2[3]);
            } else if(idx == 1) {
                swap(s1[1], s1[0]);
                swap(s2[1], s2[2]);
                swap(s3[1], s3[4]);
            } else if(idx == 2) {
                swap(s1[2], s1[1]);
                swap(s2[2], s2[5]);
            } else if(idx == 3) {
                swap(s1[3], s1[0]);
                swap(s2[3], s2[4]);
            } else if(idx == 4) {
                swap(s1[4], s1[1]);
                swap(s2[4], s2[3]);
                swap(s3[4], s3[5]);
            } else if(idx == 5) {
                swap(s1[5], s1[2]);
                swap(s2[5], s2[4]);
            }
            
            if(!vis.contains(s1)) {
                q.push({s1, step + 1});
                vis.insert(s1);
            }
            if(!vis.contains(s2)) {
                q.push({s2, step + 1});
                vis.insert(s2);
            }
            if(idx == 1 || idx == 4) {
                if(!vis.contains(s3)) {
                    q.push({s3, step + 1});
                    vis.insert(s3);
                }
            }
        }
        return ans;
    }
};
