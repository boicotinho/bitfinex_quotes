#include <pybind11/pybind11.h>
#include <marketlinks/bitfinex/market_data_feed.h>
#include <stdio.h>

class PyBook
{
public:
    PyBook(std::string const& a_market, std::string const& a_symbol)
    {
    }
};

void py_define_book(pybind11::module& m)
{
    namespace py = pybind11;
    py::class_<PyBook>(m, "Book")
    .def(py::init< std::string const&
                 , std::string const&
                 > ()
                 , py::arg("market")
                 , py::arg("symbol")
                 )
    //.def("subscribe",       &PyMarker::subscribe)
    //.def("best_bid_price",  &PyMarker::best_bid_price,  "!", py::arg("depth") = 0)
    ;
}
