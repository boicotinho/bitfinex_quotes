#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <marketlinks/bitfinex/market_data_feed.h>
#include <vector>
#include <functional>
#include <stdio.h>

using OrderId        = uint64_t;
using MarkerCallback = std::function<int(int)>;

class PyMarker
{
public:
    PyMarker( OrderId     const  a_oid
            , bool        const  a_bid
            , double      const  a_trigger
            )
    {
    }

    int func_arg(MarkerCallback const& fn)
    {
        return fn(10);
    }

private:
};


void py_define_marker(pybind11::module& m)
{
    namespace py = pybind11;
    py::class_<PyMarker>(m, "Marker")
    .def( py::init< OrderId
                  , bool
                  , double
                  > ()
                  , py::arg("oid")
                  , py::arg("bid")
                  , py::arg("trigger")
                  )
    //.def("subscribe",       &PyMarker::subscribe)
    //.def("best_bid_price",  &PyMarker::best_bid_price,  "!", py::arg("depth") = 0)
    .def("func_arg", &PyMarker::func_arg)
    ;
}
