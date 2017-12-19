#include <iostream>
#include "normalcommodity.h"

using namespace std;
#include <sstream>

int NormalCommodity::getType()const{
    return 0; //0 ��ʾ��ͨ��Ʒ
}
string NormalCommodity::getInfo()const{
    ostringstream ostr;
    ostr<<getType()<<" "; //��������ͱ���
    ostr<<Commodity::getInfo(); //����������Ϣ
    ostr<<discount<<endl; //���������Ϣ
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
    cout<<" ��Ʒ�ܼ�:"<<getNetPrice()<<" (�۸�:"
       <<getPrice()<<", ����:"<<getNum()<<", �ۿ�:"
      <<discount<<" )\n";
}
