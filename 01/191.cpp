#include<iostream>

using namespace std;

int line_x[2],line_y[2],rect_x[2],rect_y[2];

void Ipt()
{
    cin>>line_x[0]>>line_y[0]>>line_x[1]>>line_y[1]>>rect_x[0]>>rect_y[0]>>rect_x[1]>>rect_y[1];
    if(rect_x[0]>rect_x[1])swap(rect_x[0],rect_x[1]);
    if(rect_y[1]>rect_y[0])swap(rect_y[0],rect_y[1]);
}

bool check()
{
    if(line_x[0]<rect_x[0]&&line_x[1]<rect_x[0]||
       line_x[0]>rect_x[1]&&line_x[1]>rect_x[1]||
       line_y[0]>rect_y[0]&&line_y[1]>rect_y[0]||
       line_y[0]<rect_y[1]&&line_y[1]<rect_y[1])
       return false;
    float vec_x=line_x[0]-line_x[1],vec_y=line_y[0]-line_y[1];
    float rnum=line_x[0]*vec_y-line_y[0]*vec_x;   /// x*vec_y-y*vec_x-rnum=0
    if(rect_x[0]*vec_y-rect_y[0]*vec_x-rnum<0&&
       rect_x[0]*vec_y-rect_y[1]*vec_x-rnum<0&&
       rect_x[1]*vec_y-rect_y[0]*vec_x-rnum<0&&
       rect_x[1]*vec_y-rect_y[1]*vec_x-rnum<0||
       rect_x[0]*vec_y-rect_y[0]*vec_x-rnum>0&&
       rect_x[0]*vec_y-rect_y[1]*vec_x-rnum>0&&
       rect_x[1]*vec_y-rect_y[0]*vec_x-rnum>0&&
       rect_x[1]*vec_y-rect_y[1]*vec_x-rnum>0)
       return false;
    return true;
}

void Opt()
{
    if(check())
        cout<<"T\n";
    else
        cout<<"F\n";
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Ipt();
        Opt();
    }
}
