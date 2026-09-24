class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);
        int area3 = 0;
        int mnr = min(ax2, bx2), mxl = max(ax1, bx1);
        int mnt = min(ay2, by2), mxb = max(ay1, by1);
        if(mnr > mxl && mnt > mxb) area3 = (mnr - mxl) * (mnt - mxb);
        return area1 + area2 - area3;
    }
};
