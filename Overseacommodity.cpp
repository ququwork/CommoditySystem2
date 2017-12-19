#include <iostream>
#include "overseacommodity.h"
#include <sstream>
#include<string.h>
using namespace std;
int OverseaCommodity::getType()const{
    return 1; //1 ��ʾ���⹺��Ʒ
}
string OverseaCommodity::getInfo()const{
    ostringstream ostr;
    ostr<<getType()<<" "; //��������ͱ���
    ostr<<Commodity::getInfo(); //����������Ϣ
    ostr<<discount<<" "<<tariff<<endl; //���������Ϣ
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
    cout<<" ��Ʒ�ܼ�:"<<getNetPrice()<<" (�۸�:"
       <<getPrice()<<", ����:"<<getNum()<<", �ۿ�:"
      <<discount<<", ��˰:"<<tariff<<" )\n";
}
