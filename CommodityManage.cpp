#include <iostream>
#include "CommodityManage.h"
#include "Commodity.h"
#include <string>
#include <fstream>
#include "normalcommodity.h"
#include "overseacommodity.h"
using namespace std;
void CommodityManage::reAllocMemory()
{
    maxSize *= 2;
    int i;
    Commodity **temp = pCommodities;
    pCommodities = new Commodity *[maxSize];
    for (i = 0; i < size; ++i)
        pCommodities[i] = temp[i];
    delete[] temp;
}

CommodityManage::CommodityManage(int s) : maxSize(s), size(0)
{
    // pCommodities=new Commodity[maxSize];
    pCommodities = new Commodity *[maxSize];
}

CommodityManage::CommodityManage() : CommodityManage(100) {}

Commodity *CommodityManage::findCommodityById(int id) const
{
    for (int i = 0; i < size; ++i)
        if (pCommodities[i]->getId() == id)
            return pCommodities[i];
    return nullptr;
}

void CommodityManage::addCommodity(Commodity *p)
{
    if (size == maxSize)
    {
        reAllocMemory();

        return;
    }
    Commodity *pCommodity = findCommodityById(p->getId());
    if (pCommodity != nullptr)
    {
        cout << "编号为" << p->getId() << "的商品已经存在!累加其数量\n";
        pCommodity->setNum(pCommodity->getNum() + p->getNum());

        return;
    }
    pCommodities[size] = p;
    size++;
}

void CommodityManage::removeCommodity(int id)
{
    Commodity *pCommodity = findCommodityById(id);
    if (pCommodity == nullptr)
    {
        cout << "编号为" << id << "的商品不存在!\n";
        return;
    }
    //Commodity *pNext;
    delete[] pCommodity;
    size--;
    Commodity **pos = pCommodities + size;
    while (*pos != pCommodity)
    {
        pos--;
    }
    while (pos < pCommodities + size)
    { //移动指针数组中的元素
        *pos = *(pos + 1);
        pos++;
    }
}

void CommodityManage::viewCommodity(int id) const
{
    Commodity *pCommodity = findCommodityById(id);
    if (pCommodity == nullptr)
    {
        cout << "编号为" << id << "的商品不存在!\n";
        return;
    }
    pCommodity->output();
}
void CommodityManage::viewAllCommodities() const
{
    cout << "商品种类:" << size << endl;
    for (int i = 0; i < size; ++i)
        pCommodities[i]->output();
}
void CommodityManage::checkOut() const
{
    double totalPrice = 0;
    int totalNum = 0;
    cout << "商品种类: " << size << endl;
    cout << " 商品名称\t\t"
         << "价格\t"
         << "件数\t"
         << "折扣\t"
         << "总价\n";
    for (int i = 0; i < size; ++i)
    { /////////kkk

        double price = (pCommodities[i])->getNetPrice();
        cout << " " << pCommodities[i]->getName() << "\t";
        cout << pCommodities[i]->getPrice() << "\t"
             << pCommodities[i]->getNum() << "\t"
             << pCommodities[i]->getDiscount() << "\t"
             << price << endl;
        totalPrice += price;
        totalNum += pCommodities[i]->getNum();
    }

    cout << "购物篮商品总件数: " << totalNum << "\n";
    cout << "购物篮结算总价: " << totalPrice << endl;
}

void CommodityManage::saveData(string filename)
{
    ofstream out(filename);
    if (out)
    {
        out << maxSize << endl;
        out << size << endl;

        out << Commodity::getNextId() << endl; /////////////////kkk

        for (int i = 0; i < size; ++i)
        {
            out << pCommodities[i]->getInfo();
            out << pCommodities[i]->getId() << endl;
            out << pCommodities[i]->getName() << endl;
            out << pCommodities[i]->getPrice() << " "
                << pCommodities[i]->getNum() << " ";
            //     << pCommodities[i]->getDiscount()<<endl;
        }
    }
}
void CommodityManage::readData(string filename)
{
    ifstream in(filename);
    if (in)
    {
        int fileMax, fileSize;

        long nextId;
        in >> fileMax >> fileSize >> nextId;
        Commodity::setNextId(nextId);

        int type;

        double tariff;

        //  in>>fileMax>>fileSize;
        long id;
        string name, buf;
        double price, discount;
        int num;
        for (int i = 0; i < fileSize; ++i)
        {
            in >> type;
            in >> id;
            getline(in, buf); //读取 id 后残留的回车要读到 buf 中
            getline(in, name);
            in >> price >> num;
            if (type == 0)
            {
                in >> discount;
                addCommodity(new NormalCommodity(id, name, price, num, discount));
            }

            else if (type == 1)
            {
                in >> discount >> tariff;
                addCommodity(new OverseaCommodity(id, name, price, num, discount, tariff));
            }
            //            in>>price>>num>>discount;
            //            addCommodity(Commodity(id,name,price,num,discount));
        }
    }
}
