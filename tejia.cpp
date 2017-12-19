#include <iostream>
#include "tejia.h"
using namespace std;
#include <sstream>

int Tejia::getType()const{
    return 3; //3 ��ʾ�ؼ���Ʒ
}
string Tejia::getInfo()const{
    ostringstream ostr;
    ostr<<getType()<<" "; //��������ͱ���
    ostr<<Commodity::getInfo(); //����������Ϣ

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
    cout<<" ��Ʒ�ܼ�:"<<getNetPrice()<<" (�ؼۼ۸�:"
       <<getPrice()<<", ����:"<<getNum()<<")\n";
}
