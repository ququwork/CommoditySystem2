#ifndef TEJIA_H
#define TEJIA_H

#include <string>
#include "commodity.h"
class Tejia : public Commodity{
public:
    Tejia(long id,std::string name,
          double p=0,int n=0);
    Tejia(std::string name,double p=0,int n=0);

    virtual double getNetPrice()const;
    virtual void output()const;

    virtual int getType()const;
    virtual std::string getInfo()const;

private:
    double tejia;
};



#endif // TEJIA_H
