TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG +=C++11
SOURCES += main.cpp \
    CommodityManage.cpp \
    Commodity.cpp \
    Normalcommodity.cpp \
    Overseacommodity.cpp \
    function.cpp \
    ershou.cpp \
    tejia.cpp

HEADERS += \
    CommodityManage.h \
    Commodity.h \
    Normalcommodity.h \
    Overseacommodity.h \
    function.h \
    ershou.h \
    tejia.h

