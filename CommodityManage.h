#ifndef COMMODITYMANAGE_H
#define COMMODITYMANAGE_H
#include"Commodity.h"
class CommodityManage{
public:
    CommodityManage();
    CommodityManage(int s);
   // ~CommodityManage(){delete[] pCommodities;}
    CommodityManage(const CommodityManage& c)=delete;
    CommodityManage& operator=(const CommodityManage& c)=delete;
   // void addCommodity(const Commodity& c);
    void addCommodity( Commodity* p);
    void removeCommodity(int id);
    void viewCommodity(int id)const;
    void viewAllCommodities()const;
    void checkOut()const;

    void readData(std::string filename);
    void saveData(std::string filename);
private:
    //Commodity *pCommodities; //指向动态创建的商品数组
    Commodity **pCommodities; //指向动态创建的商品指针数组
    int maxSize; //当前分配的空间上限
    int size; //实际的商品数量
    Commodity* findCommodityById(int id)const;
    void reAllocMemory();

};


#endif // COMMODITYMANAGE_H
