#include <iostream>
#include "overseacommodity.h"
#include <sstream>
#include<string.h>
using namespace std;
int OverseaCommodity::getType()const{
    return 1; //1 表示海外购商品
}
string OverseaCommodity::getInfo()const{
    ostringstream ostr;
    ostr<<getType()<<" "; //先输出类型编码
    ostr<<Commodity::getInfo(); //输出基类的信息
    ostr<<discount<<" "<<tariff<<endl; //输出子类信息
    return ostr.str();
}



using namespace std;

OverseaCommodity::OverseaCommodity(long id,std::string name,
                                   double p,int n,double d,double t)
    :Commodity(id,name,p,n),discount(d),tariff(t){}
OverseaCommodity::OverseaCommodity(std::string name,double p,
                                   int n,double d,double t)
    :Commodity(name,p,n),discount(d),tariff(t){}
double OverseaCommodity::getNetPrice()const{
    return Commodity::getNetPrice()*discount+tariff;
}
void OverseaCommodity::output()const{
    Commodity::output();
    cout<<" 商品总价:"<<getNetPrice()<<" (价格:"
       <<getPrice()<<", 数量:"<<getNum()<<", 折扣:"
      <<discount<<", 关税:"<<tariff<<" )\n";
}
