
#include <iostream>
#include "function.h"
#include "normalcommodity.h"
#include "overseacommodity.h"
#include "ershou.h"
#include "tejia.h"
using namespace std;
char menu()
{
    cout << " 0) �˳�ϵͳ\n";
    cout << " 1) �����������Ʒ\n";
    cout << " 2) �ӹ������Ƴ���Ʒ\n";
    cout << " 3) �鿴ָ����Ʒ\n";
    cout << " 4) �鿴������Ʒ\n";
    cout << " 5) ����\n";
    cout << "�����빦��ѡ��:";
    char choice;
    cin >> choice;
    return choice;
}

void doAddCommodity(CommodityManage &cm)
{
    string name;
    double price, discount;

    double tariff, zhejiu;
    int num, type;
    cout << "ѡ����Ʒ����(0-��ͨ��Ʒ�� 1-���⹺��Ʒ  2-������Ʒ 3-�ؼ���Ʒ )";
    cin >> type;
    fflush(stdin);
    cout << "������Ʒ����:";
    getline(cin, name);
    cout << "����۸����Ʒ����:";
    cin >> price >> num;
    if (type == 0)
    {
        cout << "������Ʒ�ۿ�:";
        cin >> discount;
        cm.addCommodity(new NormalCommodity(name, price, num, discount));
    }
    else if (type == 1)
    {
        cout << "������Ʒ�ۿۺ͹�˰:";
        cin >> discount >> tariff;
        cm.addCommodity(new OverseaCommodity(name, price, num, discount, tariff));
    }
    else if (type == 2)
    {
        cout << "������Ʒ�ۿۺ��۾ɳ̶�:";
        cin >> discount >> zhejiu;
        cm.addCommodity(new ershou(name, price, num, discount, zhejiu));
    }
}

void doRemoveCommodity(CommodityManage &cm)
{
    long id;
    cout << "Input id:";
    cin >> id;
    cm.removeCommodity(id);
}

void doViewCommodity(const CommodityManage &cm)
{
    long id;
    cout << "Input id:";
    cin >> id;
    cm.viewCommodity(id);
}

void doViewAllCommodity(const CommodityManage &cm)
{
    cm.viewAllCommodities();
}

void doCheckout(const CommodityManage &cm)
{
    cm.checkOut();
}
