class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hAngle = (hour % 12) * 30 + ((double)minutes / 60) * 30;
        double mAngle = ((double)minutes / 60) * 360;
        double ang = abs(mAngle - hAngle);
        return min(ang, 360 - ang);
    }
};
