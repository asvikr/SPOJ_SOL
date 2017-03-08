#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x;
    int y;
    Point(int _x,int _y) : x(_x),y(_y) {}
    Point() : x(0),y(0) {}
    bool operator <(const Point& p) const {
        return x<p.x || (x==p.x && y<p.y);
    }
};

bool left_turn(const Point& p1,const Point& p2,const Point& p3) {
    return (p2.y-p1.y)*(p3.x-p1.x) - (p2.x-p1.x)*(p3.y-p1.y) > 0;
}

vector<Point> convex_hull(vector<Point> p) {
    vector<Point> ret;
    sort(p.begin(),p.end());
    for(int i=0;i<(int)p.size();i++){
        while(ret.size()>=2 && left_turn(ret[(int)ret.size()-2],ret[(int)ret.size()-1],p[i])) {
            ret.pop_back();
        }
        ret.push_back(p[i]);
    }
    
    int lower_hull_size = ret.size();

    for(int i=(int)p.size()-2;i>=0;i--){
        while((int)ret.size()-lower_hull_size>=1 && left_turn(ret[(int)ret.size()-2],ret[(int)ret.size()-1],p[i])) {
            ret.pop_back();
        }
        ret.push_back(p[i]);
    }
    return ret;
}

double triangle_area (const Point& p1, const Point& p2, const Point& p3) {
    return abs((double) p1.x * p2.y +
               (double) p2.x * p3.y +
               (double) p3.x * p1.y -
               (double) p1.y * p2.x -
               (double) p2.y * p3.x -
               (double) p3.y * p1.x) / 2.0;
}

int main() {
    int n;
    while(scanf("%d",&n) && n!=-1) {
        vector<Point> p;
        for(int i=0;i<n;i++) {
            int x,y;
            scanf("%d %d",&x,&y);
            p.push_back(Point(x,y));
        }
        p = convex_hull(p);
        p.pop_back();
        int i = 0;
        int j = i+1;
        int k = j+1;
        double res = 0;

        while(true) {
            double area = triangle_area(p[i],p[j],p[k]);
            while(true) {
                while(true) {
                    int nk = (k+1)%n;
                    double narea = triangle_area(p[i],p[j],p[nk]);
                    if(narea>=area){
                        k = nk;
                        area = narea;
                    } else {
                        break;
                    }
                }
                int nj = (j+1)%n;
                double narea = triangle_area(p[i],p[nj],p[k]);
                if(narea>=area) {
                    j = nj;
                    area = narea;
                }
                else break;
            }
            if(area>res) res = area;
            i++;
            if(i==j) j = (j+1)%n;
            if(j==k) k = (k+1)%n;
            if(i==n) break;

        }
        printf("%0.2lf\n", res);
    }
    return 0;
}
