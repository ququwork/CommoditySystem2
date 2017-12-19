#include <iostream>
#include "tejia.h"
using namespace std;
#include <sstream>

int Tejia::getType()const{
    return 3; //3 表示特价商品
}
string Tejia::getInfo()const{
    ostringstream ostr;
    ostr<<getType()<<" "; //先输出类型编码
    ostr<<Commodity::getInfo(); //输出基类的信息

    return ostr.str();
}


Tejia::Tejia(long id,std::string name,
             double p,int n)
    :Commodity(id,name,p,n){}

Tejia::Tejia(std::string name,double p,
             int n)
    :Commodity(name,p,n){}

double Tejia::getNetPrice()const{
    return Commodity::getNetPrice();
}

void Tejia::output()const{
    Commodity::output();
    cout<<" 商品总价:"<<getNetPrice()<<" (特价价格:"
       <<getPrice()<<", 数量:"<<getNum()<<")\n";
}
