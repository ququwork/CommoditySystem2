#ifndef COMMODITY_H
#define COMMODITY_H
class Commodity{
public:
    Commodity()=default;


    Commodity(long i,std::string n,double p,int nn);
    Commodity(std::string n,double p,int nn);
    void setPrice(double price){this->price=price;}
    void setNum(int num){this->num=num;}
    void setDiscount(double discount){this->discount=discount;}
    void setName(std::string name){this->name=name;}
    std::string getName()const{return name;}
    double getPrice()const{return price;}
    double getNum()const{return num;}
    double getId()const{return id;}
    double getDiscount()const{return discount;}

    virtual double getNetPrice()const;
    virtual void output()const;
    virtual int getType()const=0; //纯虚函数
    virtual std::string getInfo()const;

    static void setNextId(long id){nextId=id;}
    static long getNextId(){return nextId;}
private:
    long id;
    std::string name;
    double price; //商品数量
    int num; //购买数量
    static long nextId;/////////
    double discount;
    long autoNextId(){return nextId++;}
};
#endif // COMMODITY_H

