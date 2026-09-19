class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        long long dx = closestX - xCenter;
        long long dy = closestY - yCenter;

        return (dx * dx + dy * dy) <= (long long)radius * radius;
    }
};