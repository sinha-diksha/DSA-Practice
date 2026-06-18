class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle= 30*hour + (0.5 * minutes);
        double minAngle= 6*minutes;
        double value1 = abs(hourAngle - minAngle);
        double value3 = 360 - value1;

        return min(value1, value3);
    }
};