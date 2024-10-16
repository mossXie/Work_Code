#include <stdio.h>
#include <math.h>

typedef struct vector{
    double x;
    double y;
    double z;
} vector;

vector point(vector *len1, vector *len2){
    vector result = {
        len1->y * len2->z - len1->z * len2->y,
        len1->z * len2->x - len1->x * len2->z,
        len1->x * len2->y - len1->y * len2->x
    };
    return result;
}

double area_of_parallelogram(vector *len1, vector *len2){
    vector p = point(len1, len2);
    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

int main(){
    vector len1, len2;
    double x1 = 0, y1 = 0, z1 = 0, x2 = 0, y2 = 0, z2 = 0;

    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &z1, &x2, &y2, &z2);

    len1.x = x1;
    len1.y = y1;
    len1.z = z1;
    len2.x = x2;
    len2.y = y2;
    len2.z = z2;

    double numbe = area_of_parallelogram(&len1, &len2);
    printf("%.4lf", numbe);
    return 0;
}