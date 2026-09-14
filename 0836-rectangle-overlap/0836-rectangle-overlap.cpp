class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], x2 = rec1[2];
        int y1 = rec1[1], y2 = rec1[3];

        int a1 = rec2[0], a2 = rec2[2];
        int b1 = rec2[1], b2 = rec2[3];

        if(a1 >= x2 || a2 <= x1) return false;
        if(b1 >= y2 || b2 <= y1) return false;

        return true; 

    }
};