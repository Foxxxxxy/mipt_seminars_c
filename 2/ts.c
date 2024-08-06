#include<stdio.h>

struct point_t {
  int x, y;
};

struct triangle_t {
  struct point_t pts[3];
};

int double_area(struct triangle_t tr) {
    int m11 = tr.pts[0].x - tr.pts[2].x;
    int m12 = tr.pts[0].y - tr.pts[2].y;
    int m21 = tr.pts[1].x - tr.pts[2].x;
    int m22 = tr.pts[1].y - tr.pts[2].y;
    
    int ans = m11 * m22 - m12 * m21;

    return ans > 0 ? ans : -1 * ans;
}

int main() {
    int x1, y1, x2, y2, x3, y3;

    printf("1st point coordinates: ");
    scanf("%d%d", &x1, &y1);

    printf("2nd point coordinates: ");
    scanf("%d%d", &x2, &y2);

    printf("3rd point coordinates: ");
    scanf("%d%d", &x3, &y3);

    struct point_t p1 = { x1, y1 };

    struct point_t p2 = { x2, y2 };
    
    struct point_t p3 = { x3, y3 };
    
    struct triangle_t tr = { {p1, p2, p3} };

    int ans = double_area(tr);

    printf("%d\n", ans);

    return 0;
}
