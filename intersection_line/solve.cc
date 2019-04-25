#include <iostream>
using namespace std;
/**
 * Intersection: Given two straight line segments (represented as a start point
 * and an end point), compute the point of intersection, if any.
 */

struct Point {
  float x;
  float y;
  Point() {}
  Point(float v_x, float v_y) : x(v_x), y(v_y) {}
  bool operator<(const Point& p) { return this->x < p.x ? true : false; }
  bool operator<=(const Point& p) { return this->x <= p.x ? true : false; }
};

struct Line {
  float slope;
  float dis;
  Line(const Point& start, const Point& end) {
    slope = (end.y - start.y) / (end.x - start.x);
    dis = end.y - slope * end.x;
  }

  bool operator==(const Line& p) {
    return (this->slope == p.slope && this->dis == p.dis) ? true : false;
  }
};

void swap(Point& p1, Point& p2) {
  Point tmp = p1;
  p1 = p2;
  p2 = tmp;
}

Point* compute_intersection(Line& l1, Line& l2) {
  Point* intersec = new Point;

  intersec->x = (l2.dis - l1.dis) / (l1.slope - l2.slope);
  intersec->y = l1.slope * intersec->x + l1.dis;

  return intersec;
}

Point* intersect_line(Point& p1, Point& p2, Point& q1, Point& q2) {
  // reordering
  if (p2 < p1) swap(p1, p2);
  if (q2 < q1) swap(q1, q2);
  if (q1 < p1) {
    swap(p1, q1);
    swap(q2, p2);
  }

  Line p(p1, p2);
  Line q(q1, q2);

  // Lines in same line
  if (p == q) {
    if (p1 <= q1 && q1 <= p2)
      return &q1;
    else
      return NULL;
  } else {
    // Parallel lines
    if (p.slope == q.slope)
      return NULL;
    else {
      Point* res = compute_intersection(p, q);
      if (*res <= p2 && p1 <= *res && *res <= q2 && q1 <= *res)
        return res;
      else
        return NULL;
    }
  }
}

int main() {
  Point p1(4, 9), p2(3, 2), q1(-2, 1), q2(12, 5);
  Point* res = intersect_line(p1, p2, q1, q2);
  if (res != nullptr)
    cout << res->x << " " << res->y << endl;
  else
    cout << "not intersec" << endl;
}
