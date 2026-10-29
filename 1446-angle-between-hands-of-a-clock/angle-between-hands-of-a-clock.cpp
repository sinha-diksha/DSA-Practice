class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = 360/12;
        double minuteAngle = 360/60;
        double hourMinuteAngle = 0.5;
        double a = (double)hour * hourAngle;
        double b = (double)minutes * hourMinuteAngle;
        double finalHourAngle = a+b;
        double finalMinuteAngle = ((minutes * minuteAngle));
        double value1 = abs ( finalMinuteAngle - finalHourAngle);
        double value2 = 360 - value1;
        return min(value1, value2);
    }
};