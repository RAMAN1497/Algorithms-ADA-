#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Point {
    int x, y;
};

int orientation(Point a, Point b, Point c)
{
    int val = (b.y - a.y) * (c.x - b.x) -
              (b.x - a.x) * (c.y - b.y);

    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;  // 1 = CW, 2 = CCW
}

vector<Point> mergeHull(vector<Point> left, vector<Point> right)
{
    int n1 = left.size(), n2 = right.size();

    int iLeft = 0, iRight = 0;

    // Find rightmost point of left hull
    for(int i=1;i<n1;i++)
        if(left[i].x > left[iLeft].x)
            iLeft = i;

    // Find leftmost point of right hull
    for(int i=1;i<n2;i++)
        if(right[i].x < right[iRight].x)
            iRight = i;

    int upperLeft = iLeft, upperRight = iRight;
    bool done = false;

    // Find upper tangent
    while(!done)
    {
        done = true;
        while(orientation(right[upperRight], left[upperLeft],
                          left[(upperLeft+1)%n1]) == 2)
            upperLeft = (upperLeft+1)%n1;

        while(orientation(left[upperLeft], right[upperRight],
                          right[(n2+upperRight-1)%n2]) == 1)
        {
            upperRight = (n2+upperRight-1)%n2;
            done = false;
        }
    }

    int lowerLeft = iLeft, lowerRight = iRight;
    done = false;

    // Find lower tangent
    while(!done)
    {
        done = true;
        while(orientation(left[lowerLeft], right[lowerRight],
                          right[(lowerRight+1)%n2]) == 2)
            lowerRight = (lowerRight+1)%n2;

        while(orientation(right[lowerRight], left[lowerLeft],
                          left[(n1+lowerLeft-1)%n1]) == 1)
        {
            lowerLeft = (n1+lowerLeft-1)%n1;
            done = false;
        }
    }

    vector<Point> hull;

    // Add points from upperLeft to lowerLeft
    int idx = upperLeft;
    hull.push_back(left[idx]);
    while(idx != lowerLeft)
    {
        idx = (idx+1)%n1;
        hull.push_back(left[idx]);
    }

    // Add points from lowerRight to upperRight
    idx = lowerRight;
    hull.push_back(right[idx]);
    while(idx != upperRight)
    {
        idx = (idx+1)%n2;
        hull.push_back(right[idx]);
    }

    return hull;
}

vector<Point> divideHull(vector<Point> points)
{
    if(points.size() <= 3)
        return points;

    int mid = points.size()/2;

    vector<Point> left(points.begin(), points.begin()+mid);
    vector<Point> right(points.begin()+mid, points.end());

    left = divideHull(left);
    right = divideHull(right);

    return mergeHull(left, right);
}

int main()
{
    vector<Point> points = {
        {0,3},{2,2},{1,1},{2,1},{3,0},{0,0},{3,3}
    };

    sort(points.begin(), points.end(),
         [](Point a, Point b){
            return a.x < b.x;
         });

    vector<Point> hull = divideHull(points);

    cout<<"Convex Hull:\n";
    for(auto p : hull)
        cout<<"("<<p.x<<","<<p.y<<") ";
}
