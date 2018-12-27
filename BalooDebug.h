//
// Created by Justin Shin on 12/25/18.
//

#ifndef BALOO_BALOODEBUG_H
#define BALOO_BALOODEBUG_H

#include <boost/python.hpp>

class BalooDebug {

public:
    boost::python::dict makeDict();
    void sayHello();
};


#endif //BALOO_BALOODEBUG_H
