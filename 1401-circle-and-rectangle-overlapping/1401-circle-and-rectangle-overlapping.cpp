class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int ClosestX = max(x1,min(x2,xCenter));
        int ClosestY = max(y1,min(y2,yCenter));

        int dx = xCenter - ClosestX;
        int dy = yCenter - ClosestY;

        return (dx * dx + dy * dy) <= radius*radius;
    }
};