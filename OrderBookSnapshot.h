//
// Created by Justin Shin on 12/25/18.
//

#ifndef BALOO_ORDERBOOKSNAPSHOT_H
#define BALOO_ORDERBOOKSNAPSHOT_H

#include <map>
#include <boost/python.hpp>

#include "OrderBookMessage.h"

class OrderBookSnapshot {
public:
    boost::python::dict asksPythonDictionary();
    boost::python::dict bidsPythonDictionary();

    void applyOrderBookMessage(OrderBookMessage message);
private:
    std::map<double, double> asks;
    std::map<double, double> bids;

    boost::python::dict lastEnumeratedAsksPythonDictionary;
    boost::python::dict lastEnumeratedBidsPythonDictionary;
    bool asksNeedsEnumeration = true;
    bool bidsNeedsEnumeration = true;
};


#endif //BALOO_ORDERBOOKSNAPSHOT_H
