class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = n / rows;
        vector<vector<char>> v(rows, vector<char>(cols, ' '));
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) v[i][j] = encodedText[i * cols + j];
        }
        string ans = "";
        int r = 0, c = 0;
        while(r < rows && c < cols) {
            ans += v[r][c];
            r++, c++;
            if(r >= rows) {
                c = c - r + 1;
                r = 0;
            }
        }
        while(ans.size() > 0 && ans[ans.size() - 1] == ' ') ans.pop_back();
        return ans;
    }
};
