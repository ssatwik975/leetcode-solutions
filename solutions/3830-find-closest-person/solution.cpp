class Solution {
public:
    int findClosest(int x, int y, int z) {
    int dist1 = (x > z) ? (x - z) : (z - x);
    int dist2 = (y > z) ? (y - z) : (z - y);

    if (dist1 < dist2) return 1;
    else if (dist1 > dist2) return 2;
    else return 0;
}
};
