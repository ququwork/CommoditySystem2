# CommoditySystem2
2.2 购物篮管理系统版本 4（继承与多态）
2.2.1 继承与多态的分析与设计
2.2 shopping basket management system version 4 (inheritance and polymorphism)
2.2.1 inheritance and polymorphism analysis and design
In the Commodity class, define the id, name, price, num, and discount data member
It is the information of commodity, not universal;
There may also be second-hand goods, overseas purchases of commodities, and dealers
The algorithms for settling prices vary.
For secondhand goods, there is no concept of discounts, but there are depreciation rates
The algorithm;
In addition to the discount, additional duties are required.
Specials, special offers,
There are no other factors.
There are commonalities (basic attributes) of different commodities, and there are differences (calculation methods and losses of settlement results)
The inheritance system can be used to describe them.
Transform the Commodity in version 3 into a base class, and only define the generic genera of all commodities
Sex and method, based on commodity base class, derive SecondhandCommodity, NormalCommodity,
OverseaCommodity, SpecialCommodity, achieve their special processing logic.
Consider the notion of a Commodity (base class) array in the CommodityManage class (by pointer)
State allocated memory, which may be stored in different subclass objects for the implementation of a unified processing interface,
Polymorphic techniques should be adopted.
Create a pure c ++ console project with the name of the project named "Commodity04".
