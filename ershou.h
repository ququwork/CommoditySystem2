#ifndef ershou_H
#define ershou_H
#include <string>
#include "commodity.h"
class ershou : public Commodity{
public:
    ershou(long id,std::string name,
                     double p=0,int n=0,double d=1.0,double t=0);
    ershou(std::string name,double p=0,
                     int n=0,double d=1.0,double t=0);
    void setDiscount(double discount){this->discount=discount;}
    void setzhejiu(double zhejiu){this->zhejiu=zhejiu;}
    double getDiscount()const{return discount;}
    double getzhejiu()const{return zhejiu;}
    virtual double getNetPrice()const;
    virtual void output()const;

    virtual int getType()const;
    virtual std::string getInfo()const;

private:
    double discount;
    double zhejiu;
};
#endif // ershou_H
