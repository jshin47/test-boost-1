//
// Created by Justin Shin on 12/25/18.
//

#include "BalooDebug.h"

#include <map>
#include <iostream>
#include <boost/python.hpp>
#include "utilities.h"


using namespace boost::python;

dict BalooDebug::makeDict() {


    auto aMap = std::map<double, double>();
    aMap[0.1] = 0.2;
    return utilities::toPythonDict<double, double>(aMap);
}

void BalooDebug::sayHello() {
    std::cout << "Hello!";
}

