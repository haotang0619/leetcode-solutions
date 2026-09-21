class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // The center is int the rectangle
        if(x1 <= xCenter && x2 >= xCenter && y1 <= yCenter && y2 >= yCenter) return true;
        
        // The center is not in the rectangle
        int d1 = pow(abs(y1 - yCenter), 2), d2 = pow(abs(y2 - yCenter), 2);
        if(x2 < xCenter) d1 += pow(x2 - xCenter, 2), d2 += pow(x2 - xCenter, 2);
        else if(x1 > xCenter) d1 += pow(x1 - xCenter, 2), d2 += pow(x1 - xCenter, 2);
        
        int d3 = pow(abs(x1 - xCenter), 2), d4 = pow(abs(x2 - xCenter), 2);
        if(y2 < yCenter) d3 += pow(y2 - yCenter, 2), d4 += pow(y2 - yCenter, 2);
        else if(y1 > yCenter) d3 += pow(y1 - yCenter, 2), d4 += pow(y1 - yCenter, 2);
        
        int rr = pow(radius, 2);
        return d1 <= rr || d2 <= rr || d3 <= rr || d4 <= rr;
    }
};
