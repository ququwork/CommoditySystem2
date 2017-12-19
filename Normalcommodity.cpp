#include <iostream>
#include "normalcommodity.h"

using namespace std;
#include <sstream>

int NormalCommodity::getType()const{
    return 0; //0 表示普通商品
}
string NormalCommodity::getInfo()const{
    ostringstream ostr;
    ostr<<getType()<<" "; //先输出类型编码
    ostr<<Commodity::getInfo(); //输出基类的信息
    ostr<<discount<<endl; //输出子类信息
    return ostr.str();
}


NormalCommodity::NormalCommodity(long id,std::string name,
                                 double p,int n,double d)
    :Commodity(id,name,p,n),discount(d){}

NormalCommodity::NormalCommodity(std::string name,double p,
                                 int n,double d)
    :Commodity(name,p,n),discount(d){}

double NormalCommodity::getNetPrice()const{
    return Commodity::getNetPrice()*discount;
}

void NormalCommodity::output()const{
    Commodity::output();
    cout<<" 商品总价:"<<getNetPrice()<<" (价格:"
       <<getPrice()<<", 数量:"<<getNum()<<", 折扣:"
      <<discount<<" )\n";
}
