
#include <iostream>
#include "Commodity.h"
#include "CommodityManage.h"
#include "function.h"
using namespace std;
int main(){
    cout<<"欢迎使用购物篮管理系统!\n";
    char choice;
    CommodityManage cm; 
    cm.readData("commodity04.data");
    while(true){
        choice=menu();
        if(choice=='0')
            break;
        switch(choice){
        case '1':
            doAddCommodity(cm);
            break;
        case '2':
            doRemoveCommodity(cm);
            break;
        case '3':
            doViewCommodity(cm);
            break;
        case '4':
            doViewAllCommodity(cm);
            break;
        case '5':
            doCheckout(cm);
            break;
        default:
            cout<<"无效输入! 请重试!\n";
            break;
        }
    }
    cout<<"再见!\n";
    cm.saveData("commodity04data");


    return 0;
}
