#include <stdio.h>
#include <stdbool.h>

// Téglatest struktúra
typedef struct {
    double length;
    double width;
    double height;
} Cuboid;

// Függvény a téglatest méreteinek beállítására (ellenőrzött módon)
void set_size(Cuboid *c, double length, double width, double height) {
    if (length > 0 && width > 0 && height > 0) {
        c->length = length;
        c->width = width;
        c->height = height;
    } else {
        printf("Hibás méretek! Minden értéknek pozitívnak kell lennie.\n");
    }
}

// Függvény a térfogat kiszámítására
double calc_volume(Cuboid c) {
    return c.length * c.width * c.height;
}

// Függvény a felszín kiszámítására
double calc_surface(Cuboid c) {
    return 2 * (c.length * c.width + c.length * c.height + c.width * c.height);
}

// Függvény annak ellenőrzésére, hogy van-e négyzet alakú lapja
bool has_square_face(Cuboid c) {
    return (c.length == c.width || c.length == c.height || c.width == c.height);
}

int main() {
    Cuboid cuboid;
    double length, width, height;
    
    printf("Adja meg a teglatest hosszat: ");
    scanf("%lf", &length);
    printf("Adja meg a teglatest szelesseget: ");
    scanf("%lf", &width);
    printf("Adja meg a teglatest magassagat: ");
    scanf("%lf", &height);
    
    set_size(&cuboid, length, width, height);
    
    printf("Terfogat: %.2f\n", calc_volume(cuboid));
    printf("Felszin: %.2f\n", calc_surface(cuboid));
    
    if (has_square_face(cuboid)) {
        printf("A teglatestnek van negyzet alaku lapja.\n");
    } else {
        printf("A teglatestnek nincs negyzet alaku lapja.\n");
    }
    
    return 0;
}
