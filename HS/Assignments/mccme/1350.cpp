#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;


struct Point {

    double x,y;
    Point()
    {
        x=y=0;
    }
    Point(double xx,double yy)
    {
        x=xx;
        y=yy;
    }

    void read()
    {
        scanf("%lf%lf",&x,&y);
    }

    Point operator-(Point a)
    {
        return Point(x-a.x,y-a.y);
    }
    double operator*(Point a)
    {
        return x*a.y-y*a.x;
    }
    double scal(Point a)
    {
        return x*a.x+y*a.y;
    }

    void makeLen(double l)
    {
        double dist = sqrt(x*x+y*y);
        x*=l/dist;
        y*=l/dist;
    }


};

double a,b,c;


int main()
{


    scanf("%lf%lf%lf",&a,&b,&c);
    Point p ;

    p.read();

    double l = fabs(a*p.x+b*p.y+c)/sqrt(a*a+b*b);

    Point norm = Point(a,b);
    Point p1;

    if (a!=0) p1= Point(-c/a,0); else
        p1 = Point(0,-c/b);

    if (norm.scal(p-p1)  <  0) norm.x*=-1,norm.y*=-1;

    norm.makeLen(l);
    Point p2 = p - norm;

    printf("%.5lf %.5lf",p2.x  - norm.x , p2.y-norm.y);
    return 0;
}
