class Solution {
public:
    void traverse(vector<vector<int>>& image, int i, int j, int tar, int orig) {
        if(tar == orig) return;
        image[i][j] = tar;
        int m = image.size(), n = image[0].size();
        if(i > 0 && image[i - 1][j] == orig) traverse(image, i - 1, j, tar, orig);
        if(i < m - 1 && image[i + 1][j] == orig) traverse(image, i + 1, j, tar, orig);
        if(j > 0 && image[i][j - 1] == orig) traverse(image, i, j - 1, tar, orig);
        if(j < n - 1 && image[i][j + 1] == orig) traverse(image, i, j + 1, tar, orig);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        traverse(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};
