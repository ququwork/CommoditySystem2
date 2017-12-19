#include <iostream>
#include "ershou.h"
#include <sstream>
#include<string.h>
using namespace std;
int ershou::getType()const{
    return 2; //2 表示二手商品
}
string ershou::getInfo()const{
    ostringstream ostr;
    ostr<<getType()<<" "; //先输出类型编码
    ostr<<Commodity::getInfo(); //输出基类的信息
    ostr<<discount<<" "<<zhejiu<<endl; //输出子类信息
    return ostr.str();
}



using namespace std;

ershou::ershou(long id,std::string name,
                                   double p,int n,double d,double t)
    :Commodity(id,name,p,n),discount(d),zhejiu(t){}

ershou::ershou(std::string name,double p,
                                   int n,double d,double t)
    :Commodity(name,p,n),discount(d),zhejiu(t){}

double ershou::getNetPrice()const{
    return Commodity::getNetPrice()*discount*zhejiu;
}
void ershou::output()const{
    Commodity::output();
    cout<<" 商品总价:"<<getNetPrice()<<" (价格:"
       <<getPrice()<<", 数量:"<<getNum()<<", 折扣:"
      <<discount<<", 折旧:"<<zhejiu<<" )\n";
}
