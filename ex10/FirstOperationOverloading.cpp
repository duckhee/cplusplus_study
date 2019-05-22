#include <iostream>

using namespace std;

class Point
{
    private:
        int xpos, ypos;
    public:
        Point(int x = 0, int y = 0):xpos(x), ypos(y)
        {

        }
        void ShowPostion() const
        {
            cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
        }
        Point operator+(const Point &ref)
        {
            Point pos(xpos+ref.xpos, ypos+ref.ypos);
            return pos;
        }
};

int main()
{
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3 = pos1.operator+(pos2);
    pos1.ShowPostion();
    pos2.ShowPostion();
    pos3.ShowPostion();

    return 0;
}