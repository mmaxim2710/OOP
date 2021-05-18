#ifndef D_POINT_H_
#define D_POINT_H_

#include <istream>
#include <ostream>

class Point {
    public:
        double x, y;
        Point();
        Point(double a, double b);
        Point& operator=(const Point& other);
        Point operator+(const Point& other);
        Point operator-(const Point& other);
        Point operator/(const double num);
        ~Point() = default;
        
        friend std::istream& operator>> (std::istream& is, Point& p);
        friend std::ostream& operator<< (std::ostream& os, const Point& p);
};


#endif //D_POINT_H_