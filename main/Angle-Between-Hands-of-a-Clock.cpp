1class Solution {
2public:
3    double angleClock(int hour, int minutes) {
4        double angle_min = minutes * 6.0;
5        double angle_hour = (hour % 12 * 30.0) + (minutes * 0.5);
6        double diff = std::abs(angle_hour - angle_min);
7        return std::min(diff, 360.0 - diff);
8    }
9};