// Define a structure to represent a point in 2D space with x and y coordinates. Implement functions to calculate the distance between two points and to check if a point lies within a specific rectangular boundary.
#include <stdio.h>
#include <math.h>
typedef struct {
    float x, y;
} Point;
float calculateDistance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}
int isPointInRectangle(Point p, Point topLeft, Point bottomRight) {
    return (p.x >= topLeft.x && p.x <= bottomRight.x && p.y <= topLeft.y && p.y >= bottomRight.y);
}
int main() {
    Point p1 = {2, 3}, p2 = {5, 7}, topLeft = {0, 8}, bottomRight = {10, 0};
    printf("Distance: %.2f\n", calculateDistance(p1, p2));
    printf("Point in rectangle: %s\n", isPointInRectangle(p1, topLeft, bottomRight) ? "Yes" : "No");
    return 0;
}
