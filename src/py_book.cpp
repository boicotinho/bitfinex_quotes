#include "py_book.h"
#include <pybind11/pybind11.h>
#include <marketlinks/bitfinex/market_data_feed.h>
#include <stdio.h>

void py_define_book(pybind11::module& m)
{
    namespace py = pybind11;
    py::class_<PyBook, PyBookPtr>(m, "Book")
    .def( py::init< std::string const&
                  , std::string const&
                  > ()
                  , py::arg("market")
                  , py::arg("symbol")
        )
    //.def("subscribe",       &PyMarker::subscribe)
    //.def("best_bid_price",  &PyMarker::best_bid_price,  "!", py::arg("depth") = 0)
    ;
}
