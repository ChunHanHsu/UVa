#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;

int main(){
    float x_a,y_a,x_b,y_b,x_c,y_c;
    //ofstream fout("out.txt");
    ostream& outs(cout);

    while(cin>>x_a>>y_a>>x_b>>y_b>>x_c>>y_c){
        float   normal_ab_x,normal_ab_y,normal_ab_c,
                normal_ac_x,normal_ac_y,normal_ac_c,//ax+by=c
                mid_ab_x,mid_ab_y,
                mid_ac_x,mid_ac_y;
        normal_ab_x=x_a-x_b;//a
        normal_ab_y=y_a-y_b;//b
        normal_ac_x=x_a-x_c;//d
        normal_ac_y=y_a-y_c;//e
        mid_ab_x=(x_a+x_b)/2.0;
        mid_ab_y=(y_a+y_b)/2.0;
        mid_ac_x=(x_a+x_c)/2.0;
        mid_ac_y=(y_a+y_c)/2.0;
        normal_ab_c=mid_ab_x*normal_ab_x+mid_ab_y*normal_ab_y;//c
        normal_ac_c=mid_ac_x*normal_ac_x+mid_ac_y*normal_ac_y;//f
        float h,k,r;
        h = (normal_ab_c*normal_ac_y-normal_ac_c*normal_ab_y)/
            (normal_ac_y*normal_ab_x-normal_ab_y*normal_ac_x);
        k = (normal_ab_c*normal_ac_x-normal_ac_c*normal_ab_x)/
            (normal_ab_y*normal_ac_x-normal_ab_x*normal_ac_y);
        r = pow((x_a-h)*(x_a-h)+(y_a-k)*(y_a-k),0.5);
        float c,d,e;
        c = h*-2.0;
        d = k*-2.0;
        e = -r*r+h*h+k*k;

        outs<<"(x ";
        if(h>=0.000001)outs<<"- "<<fixed  << setprecision(3)<<h<<")^2 + (y ";
        else outs<<"+ "<< fixed  <<setprecision(3)<<-h<<")^2 + (y ";
        if(k>=0.000001)outs<<"- "<<fixed  << setprecision(3)<<k<<")^2 = ";
        else outs<<"+ "<<fixed  << setprecision(3)<<-k<<")^2 = ";
        outs<<fixed  <<setprecision(3)<<r<<"^2"<<endl;
        outs<<"x^2 + y^2 ";
        if(c>=0.000001)outs<<"+ "<<fixed  << setprecision(3)<<c<<"x ";
        else outs<<"- "<<fixed  << setprecision(3)<<-c<<"x ";
        if(d>=0.000001)outs<<"+ "<<fixed  << setprecision(3)<<d<<"y ";
        else outs<<"- "<< fixed  <<setprecision(3)<<-d<<"y ";
        if(e>=0.000001)outs<<"+ "<<fixed  << setprecision(3)<<e<<" = 0"<<endl<<endl;
        else outs<<"- "<<fixed  << setprecision(3)<<-e<<" = 0"<<endl<<endl;
    }
    return 0;
}
