//
// Created by Justin Shin on 12/25/18.
//

#include "OrderBookSnapshot.h"

#include <boost/python.hpp>

#include "utilities.h"

using namespace boost::python;
//
//void OrderBookSnapshot::applyOrderBookMessage(OrderBookMessage message) {
//    auto whichMap = (message.direction == Ask) ? asks : bids;
//    if (message.quantity > 0)
//        whichMap[message.price] = message.quantity;
//    else
//        whichMap.erase(message.price);
//}

void OrderBookSnapshot::applyOrderBookMessage(OrderBookMessage message) {
    auto whichMap = (message.getDirection() == Ask) ? asks : bids;
    if (message.getQuantity() > 0)
        whichMap[message.getPrice()] = message.getQuantity();
    else
        whichMap.erase(message.getPrice());
}

dict OrderBookSnapshot::asksPythonDictionary() {
    if (asksNeedsEnumeration) {
        lastEnumeratedAsksPythonDictionary = utilities::toPythonDict<double, double>(asks);
        asksNeedsEnumeration = false;
    }
    return lastEnumeratedAsksPythonDictionary;
}

dict OrderBookSnapshot::bidsPythonDictionary() {
    if (bidsNeedsEnumeration) {
        lastEnumeratedBidsPythonDictionary = utilities::toPythonDict<double, double>(bids);
        bidsNeedsEnumeration = false;
    }
    return lastEnumeratedBidsPythonDictionary;
}
