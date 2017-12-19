
#include <iostream>
#include "function.h"
#include "normalcommodity.h" 
#include "overseacommodity.h"
#include "ershou.h"
#include "tejia.h"
using namespace std;
char menu()
{
    cout << " 0) 退出系统\n";
    cout << " 1) 向购物篮添加商品\n";
    cout << " 2) 从购物篮移除商品\n";
    cout << " 3) 查看指定商品\n";
    cout << " 4) 查看所有商品\n";
    cout << " 5) 结算\n";
    cout << "请输入功能选项:";
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
    cout << "选择商品类型(0-普通商品， 1-海外购商品  2-二手商品 3-特价商品 )";
    cin >> type;
    fflush(stdin);
    cout << "输入商品名称:";
    getline(cin, name);
    cout << "输入价格和商品数量:";
    cin >> price >> num;
    if (type == 0)
    {
        cout << "输入商品折扣:";
        cin >> discount;
        cm.addCommodity(new NormalCommodity(name, price, num, discount));
    }
    else if (type == 1)
    {
        cout << "输入商品折扣和关税:";
        cin >> discount >> tariff;
        cm.addCommodity(new OverseaCommodity(name, price, num, discount, tariff));
    }
    else if (type == 2)
    {
        cout << "输入商品折扣和折旧程度:";
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
