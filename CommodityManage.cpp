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
        cout << "���Ϊ" << p->getId() << "����Ʒ�Ѿ�����!�ۼ�������\n";
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
        cout << "���Ϊ" << id << "����Ʒ������!\n";
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
    { //�ƶ�ָ�������е�Ԫ��
        *pos = *(pos + 1);
        pos++;
    }
}

void CommodityManage::viewCommodity(int id) const
{
    Commodity *pCommodity = findCommodityById(id);
    if (pCommodity == nullptr)
    {
        cout << "���Ϊ" << id << "����Ʒ������!\n";
        return;
    }
    pCommodity->output();
}
void CommodityManage::viewAllCommodities() const
{
    cout << "��Ʒ����:" << size << endl;
    for (int i = 0; i < size; ++i)
        pCommodities[i]->output();
}
void CommodityManage::checkOut() const
{
    double totalPrice = 0;
    int totalNum = 0;
    cout << "��Ʒ����: " << size << endl;
    cout << " ��Ʒ����\t\t"
         << "�۸�\t"
         << "����\t"
         << "�ۿ�\t"
         << "�ܼ�\n";
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

    cout << "��������Ʒ�ܼ���: " << totalNum << "\n";
    cout << "�����������ܼ�: " << totalPrice << endl;
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
            getline(in, buf); //��ȡ id ������Ļس�Ҫ���� buf ��
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
