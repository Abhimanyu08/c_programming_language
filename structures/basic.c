#include <stdio.h>

struct point {
	int x;
	int y;
    };


struct point makepoint(int x, int y) {
    struct point pt;
    pt.x = x;
    pt.y = y;
    return pt;
}


struct point addpoint(struct point p1, struct point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    
    return p1;

}

main() {
    
    struct rect {
	struct point pt1;
	struct point pt2;
    };
    int XMAX = 100;
    int YMAX = 100;
    
    struct rect screen;
    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);

    struct point middle;


    middle = makepoint((screen.pt1.x + screen.pt2.x)/2, (screen.pt1.y + screen.pt2.y)/2);

    printf("middle x:%d, middle y:%d\n", middle.x, middle.y);

    addpoint(screen.pt1, screen.pt2);


    printf("pt1.x: %d, pt1.y: %d\n", screen.pt1.x, screen.pt1.y);


}
