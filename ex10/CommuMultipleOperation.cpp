#include <iostream>

using namespace std;

class Point
{
    public:
        int xpos, ypos;
    public:
        Point(int x = 0, int y = 0):xpos(x), ypos(y)
        {

        }
        void ShowPosition() const
        {
            cout<<'['<<xpos<<", "<<ypos<<']';
        }
        Point operator*(int times)
        {
            Point pos(xpos*times, ypos*times);
            return pos;
        }
        friend Point operator*(int times, Point &ref)
        {
            return ref*times;
        }
};

int main()
{
    Point pos(1, 2);
    Point cpy;
    cpy = pos*3;
    cpy.ShowPosition();

    cpy = 2*pos*3;
    cpy.ShowPosition();

    return 0;

}