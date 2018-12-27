//
// Created by Justin Shin on 12/25/18.
//

#include <map>
#include <boost/python.hpp>
#include "utilities.h"
#include "BalooDebug.h"
#include "OrderBookSnapshot.h"
#include "OrderBookMessage.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(baloo) {
    class_<BalooDebug>("BalooDebug")
            .def_readonly("asks", &BalooDebug::makeDict)
            .def("say_hello", &BalooDebug::sayHello)
            ;
    class_<OrderBookSnapshot>("OrderBookSnapshot")
            .def_readonly("asks", &OrderBookSnapshot::asksPythonDictionary)
            .def_readonly("bids", &OrderBookSnapshot::bidsPythonDictionary)
            .def("apply_message", &OrderBookSnapshot::applyOrderBookMessage)
    ;

    class_<OrderBookMessage>("OrderBookMessage")
            .add_property("timestamp", &OrderBookMessage::getTimestamp, &OrderBookMessage::setTimestamp)
            .add_property("price", &OrderBookMessage::getPrice, &OrderBookMessage::setPrice)
            .add_property("quantity", &OrderBookMessage::getQuantity, &OrderBookMessage::setQuantity)
            .add_property("direction", &OrderBookMessage::getDirection, &OrderBookMessage::setDirection)
            ;

    enum_<OrderBookMessageDirection>("OrderBookMessageDirection")
            .value("Ask", Ask)
            .value("Bid", Bid)
            .export_values()
            ;
}

