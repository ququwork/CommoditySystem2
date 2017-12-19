#include <iostream>
#include "ershou.h"
#include <sstream>
#include<string.h>
using namespace std;
int ershou::getType()const{
    return 2; //2 ��ʾ������Ʒ
}
string ershou::getInfo()const{
    ostringstream ostr;
    ostr<<getType()<<" "; //��������ͱ���
    ostr<<Commodity::getInfo(); //����������Ϣ
    ostr<<discount<<" "<<zhejiu<<endl; //���������Ϣ
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
    cout<<" ��Ʒ�ܼ�:"<<getNetPrice()<<" (�۸�:"
       <<getPrice()<<", ����:"<<getNum()<<", �ۿ�:"
      <<discount<<", �۾�:"<<zhejiu<<" )\n";
}
