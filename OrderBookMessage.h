//
// Created by Justin Shin on 12/25/18.
//

#ifndef BALOOCONTRIB_ORDERBOOKMESSAGE_H
#define BALOOCONTRIB_ORDERBOOKMESSAGE_H

#include <tuple>
#include <map>
#include <string>
#include <sstream>
#include <vector>

#include <boost/python.hpp>
#include <boost/date_time.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time/posix_time/conversion.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>

#include "OrderBookMessageDirection.h"
#include "utilities.h"

class OrderBookMessage {
public:
    boost::posix_time::ptime getTimestamp();
    void setTimestamp(boost::posix_time::ptime timestamp);
    double getPrice();
    void setPrice(double price);
    double getQuantity();
    void setQuantity(double quantity);
    OrderBookMessageDirection getDirection();
    void setDirection(OrderBookMessageDirection direction);
private:
    boost::posix_time::ptime timestamp;
    double price;
    double quantity;
    OrderBookMessageDirection  direction;
};


#endif //BALOOCONTRIB_ORDERBOOKMESSAGE_H
