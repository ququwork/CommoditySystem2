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
    //Commodity *pCommodities; //ָ��̬��������Ʒ����
    Commodity **pCommodities; //ָ��̬��������Ʒָ������
    int maxSize; //��ǰ����Ŀռ�����
    int size; //ʵ�ʵ���Ʒ����
    Commodity* findCommodityById(int id)const;
    void reAllocMemory();

};


#endif // COMMODITYMANAGE_H
