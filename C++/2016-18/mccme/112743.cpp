#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
const double EPS = 1E-9;

struct pt {
    friend istream& operator >> (istream & is, pt & p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator<< (ostream &os, pt& p) {
        os << p.x << " " << p.y << endl;
        return os;
    }

    bool operator< (const pt & p) const {
        return x < p.x - EPS || abs(x - p.x) < EPS && y < p.y - EPS;
    }

    double x;
    double y;
};

struct line {
    double a, b, c;

    line() {}
    line(pt p, pt q) {
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a * p.x - b * p.y;
        norm();
    }

    void norm() {
        double z = sqrt(a*a + b*b);
        if (abs(z) > EPS)
            a /= z, b /= z, c /= z;
    }

    double dist(pt p) const {
        return a * p.x + b * p.y + c;
    }
};

#define det(a,b,c,d)  (a*d-b*c)

inline bool between(double l, double r, double x) {
    return min(l, r) <= x + EPS && x <= max(l, r) + EPS;
}

inline bool intersect_dimension(double a, double b, double c, double d) {
    if (a > b)  swap(a, b);
    if (c > d)  swap(c, d);
    return max(a, c) <= min(b, d) + EPS;
}

bool intersect(pt a, pt b, pt c, pt d, pt & left, pt & right) {
    if (!intersect_dimension(a.x, b.x, c.x, d.x) || !intersect_dimension(a.y, b.y, c.y, d.y))
        return false;
    line m(a, b);
    line n(c, d);
    double zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < EPS) {
        if (abs(m.dist(c)) > EPS || abs(n.dist(a)) > EPS)
            return false;
        if (b < a)  swap(a, b);
        if (d < c)  swap(c, d);
        left = max(a, c);
        right = min(b, d);
        return true;
    }
    else {
        left.x = right.x = -det(m.c, m.b, n.c, n.b) / zn;
        left.y = right.y = -det(m.a, m.c, n.a, n.c) / zn;
        return between(a.x, b.x, left.x)
            && between(a.y, b.y, left.y)
            && between(c.x, d.x, left.x)
            && between(c.y, d.y, left.y);
    }
}

int main() {
    pt A, B, C, D;
    cin >> A >> B >> C >> D;
    pt l, r;
    bool check = intersect(A, B, C, D, l, r);
    cout << fixed;
    cout.precision(6);
    if (check) {
        if (l.x == r.x && l.y == r.y) {
            cout << l.x << " " <<  l.y << endl;
        }
        else {
            cout << l.x << " " << l.y << endl;
            cout << r.x << " " << r.y << endl;
        }
    }
    else {
        cout << "Empty";
    }
    return 0;
}
