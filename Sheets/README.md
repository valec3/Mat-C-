# Algoritmos tipicos

## Primos

- (Ver si un numero es primo)[#]
```c++
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
 
    return true;
}
```

### Gauss
```c++
int gauss(int n) {
    return (n * (n + 1)) / 2;
}
```

## Geometria
### Punto
```c++
struct point {
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
    point operator + (const point &p) const { return point(x + p.x, y + p.y); }
    point operator - (const point &p) const { return point(x - p.x, y - p.y); }
    point operator * (double k) const { return point(x * k, y * k); }
    point operator / (double k) const { return point(x / k, y / k); }
    bool operator == (const point &p) const { return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS; }
    bool operator != (const point &p) const { return !(p == *this); }
    bool operator < (const point &p) const { return x < p.x - EPS || (fabs(x - p.x) < EPS && y < p.y - EPS); }
    double dot(const point &p) const { return x * p.x + y * p.y; }
    double cross(const point &p) const { return x * p.y - y * p.x; }
    double norm() const { return sqrt(dot(*this)); }
    double norm2() const { return dot(*this); }
    double dist(const point &p) const { return (*this - p).norm(); }
    double dist2(const point &p) const { return (*this - p).norm2(); }
    point rotate(double alpha) const { return point(x * cos(alpha) - y * sin(alpha), x * sin(alpha) + y * cos(alpha)); }
    point unit() const { return *this / norm(); }
    point perp() const { return point(-y, x); }
    point normal() const { return perp().unit(); }
    point trunc(double k) const { return unit() * k; }
    point rotate(const point &p, double alpha) const { return (*this - p).rotate(alpha) + p; }
    point reflect(const point &p, const point &q) const { return p + ((*this - p) / (q - p)).conj() * (q - p); }
    point reflect(const point &p) const { return reflect(p, point(0, 0)); }
    point proj(const point &p, const point &q) const { return p + ((*this - p) * (q - p)).conj() * (q - p); }
    point proj(const point &p) const { return proj(p, point(0, 0)); }
    point conj() const { return point(x, -y); }
    point perp(const point &p, const point &q) const { return proj(p, q) * 2 - *this; }
    point perp(const point &p) const { return perp(p, point(0, 0)); }
    double angle(const point &p, const point &q) const { return atan2(cross(p, q), dot(p, q)); }
    double angle(const point &p) const { return angle(p, point(0, 0)); }
    double angle() const { return angle(point(1, 0)); }
    double orientedAngle(const point &p, const point &q) const { return angle(p, q) < 0 ? angle(p, q) + 2 * PI : angle(p, q); }
    double orientedAngle(const point &p) const { return orientedAngle(p, point(0, 0)); }
    double orientedAngle() const { return orientedAngle(point(1, 0)); }
    double orientedAngle(const point &p, const point &q, const point &r) const { return orientedAngle(p - r, q - r); }
    double orientedAngle(const point &p, const point &q) const { return orientedAngle(p, q, point(0, 0)); }
    double orientedAngle(const point &p) const { return orientedAngle(p, point(0, 0)); }
    bool inAngle(const point &p, const point &q, const point &r) const { return sign(cross(p, q)) * sign(cross(p, r)) >= 0; }
    bool inAngle(const point &p, const point &q) const { return inAngle(p, point(0, 0), q); }
    bool inAngle(const point &p) const { return inAngle(p, point(1, 0)); }
    bool onSegment(const point &p, const point &q) const { return sign(cross(*this - p, q - p)) == 0 && sign(dot(*this - p, *this - q)) <= 0; }
    bool onSegment(const point &p) const { return onSegment(point(0, 0), p); }
}
```
### Linea
```c++
    struct line{
        point p, q;
        line() {}
        line(point p, point q) : p(p), q(q) {}
        bool operator == (const line &l) const { return p == l.p && q == l.q; }
        bool operator != (const line &l) const { return !(*this == l); }
        bool operator < (const line &l) const { return q < l.q - EPS || (fabs(q.x - l.q.x) < EPS && q.y < l.q.y - EPS); }
        point vec() const { return q - p; }
        point unit() const { return vec() / vec().norm(); }
        point perp() const { return vec().perp(); }
        point normal() const { return vec().normal(); }
        line translate(double d) const { return line(p + vec().perp().trunc(d), q + vec().perp().trunc(d)); }
        line shiftLeft(double d) const { return line(p + vec().unit().rotate(PI / 2) * d, q + vec().unit().rotate(PI / 2) * d); }
        line shiftRight(double d) const { return shiftLeft(-d); }
        line dilate(double k) const { return line(p, p + vec() * k); }
        line translate(const point &t) const { return line(p + t, q + t); }
        line shiftLeft(const point &t) const { return shiftLeft(t.norm()); }
        line shiftRight(const point &t) const { return shiftRight(t.norm()); }
        line dilate(const point &t) const { return line(p + t, p + vec() * t.norm()); }
        bool onLine(const point &r) const { return sign(cross(vec(), r - p)) == 0; }
        bool onSegment(const point &r) const { return sign(cross(vec(), r - p)) == 0 && sign(dot(r - p, r - q)) <= 0; }
        bool onLeft(const point &r) const { return sign(cross(vec(), r - p)) > 0; }
        bool onRight(const point &r) const { return sign(cross(vec(), r - p)) < 0; }
        double dist(const point &r) const { return fabs(cross(vec(), r - p)) / vec().norm(); }
    }
```

### Segmento
```c++
struct segment {
    point p, q;
    segment() {}
    segment(point p, point q) : p(p), q(q) {}
    bool operator == (const segment &s) const { return p == s.p && q == s.q; }
    bool operator != (const segment &s) const { return !(*this == s); }
    bool operator < (const segment &s) const { return q < s.q - EPS || (fabs(q.x - s.q.x) < EPS && q.y < s.q.y - EPS); }
    point vec() const { return q - p; }
    point unit() const { return vec() / vec().norm(); }
    point perp() const { return vec().perp(); }
    point normal() const { return vec().normal(); }
    segment translate(double d) const { return segment(p + vec().perp().trunc(d), q + vec().perp().trunc(d)); }
    segment shiftLeft(double d) const { return segment(p + vec().unit().rotate(PI / 2) * d, q + vec().unit().rotate(PI / 2) * d); }
    segment shiftRight(double d) const { return shiftLeft(-d); }
    segment dilate(double k) const { return segment(p, p + vec() * k); }
    segment translate(const point &t) const { return segment(p + t, q + t); }
    segment shiftLeft(const point &t) const { return shiftLeft(t.norm()); }
    segment shiftRight(const point &t) const { return shiftRight(t.norm()); }
    segment dilate(const point &t) const { return segment(p + t, p + vec() * t.norm()); }
    bool onLine(const point &r) const { return sign(cross(vec(), r - p)) == 0; }
    bool onSegment(const point &r) const { return sign(cross(vec(), r - p)) == 0 && sign(dot(r - p, r - q)) <= 0; }
    bool onLeft(const point &r) const { return sign(cross(vec(), r - p)) > 0; }
    bool onRight(const point &r) const { return sign(cross(vec(), r - p)) < 0; }
    double dist(const point &r) const { return fabs(cross(vec(), r - p)) / vec().norm(); }
}
```
### Circulo
```c++
struct circle {
    point c;
    double r;
    circle() {}
    circle(point c, double r) : c(c), r(r) {}
    bool operator == (const circle &c) const { return this->c == c.c && fabs(r - c.r) < EPS; }
    bool operator != (const circle &c) const { return !(*this == c); }
    bool operator < (const circle &c) const { return r < c.r - EPS || (fabs(r - c.r) < EPS && c.c < this->c - EPS); }
    bool operator > (const circle &c) const { return r > c.r + EPS || (fabs(r - c.r) < EPS && c.c > this->c + EPS); }
    bool operator <= (const circle &c) const { return *this < c || *this == c; }
    bool operator >= (const circle &c) const { return *this > c || *this == c; }
    double area() const { return PI * r * r; }
    double circumference() const { return 2 * PI * r; }
    double arc(double alpha) const { return alpha * r; }
    double chord(double alpha) const { return 2 * r * sin(alpha / 2); }
    double sector(double alpha) const { return alpha * r * r / 2; }
    double segment(double alpha) const { return sector(alpha) - r * r * sin(alpha) / 2; }
    bool contains(const point &p) const { return c.dist(p) < r + EPS; }
    bool contains(const circle &c) const { return c.c.dist(c.c) + c.r < r + EPS; }
    bool intersects(const circle &c) const { return !contains(c) && !c.contains(*this) && c.c.dist(c.c) < r + c.r + EPS; }
    bool disjoint(const circle &c) const { return !intersects(c); }
    bool touches(const circle &c) const { return !intersects(c) && !disjoint(c); }
    vector<point> intersectionPoints(const circle &c) const {
        vector<point> ans;
        if(intersects(c)) {
            double d = c.c.dist(c.c);
            double alpha = acos((r * r + d * d - c.r * c.r) / (2 * r * d));
            point p = (c.c - c.c).unit().rotate(alpha) * r + c.c;
            point q = (c.c - c.c).unit().rotate(-alpha) * r + c.c;
            ans.push_back(p);
            if(p != q) ans.push_back(q);
        }
        return ans;
    }
    vector<line> tangentLines(const point &p) const {
        vector<line> ans;
        if(!contains(p)) {
            double d = c.dist(p);
            double alpha = asin(r / d);
            point v = (p - c).unit().rotate(alpha) * sqrt(d * d - r * r);
            point p = c + v;
            point q = c - v;
            ans.push_back(line(p, p + v.perp()));
            if(p != q) ans.push_back(line(q, q + v.perp()));
        }
        return ans;
    }
}
```
### Poligono
