#include "py_book.h"
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <marketlinks/bitfinex/market_data_feed.h>
#include <vector>
#include <thread>
#include <memory>
#include <functional>
#include <stdio.h>
class PyMarker
{
public:
    PyMarker( OrderId        const  a_cl_oid
            , eSide          const  a_side
            , double         const  a_price_delta
            , MarkerCallback const& a_callback
            , PyBookPtr      const& a_book
            )
            : m_callback(a_callback)
            , m_thread([this](){this->run_thread();})
    {
    }

    ~PyMarker()
    {
        stop();
    }

    void stop() noexcept
    {
        m_quit = true;
        if(m_thread.joinable())
            m_thread.join();
    }

    void run_thread()
    {
        fprintf(stderr, "Thread started\n");
        while(!m_quit)
        {
            fprintf(stderr, "ThreadRun\n");
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
        fprintf(stderr, "Thread stopped\n");
    }

    int func_arg(MarkerCallback const& fn)
    {
        return fn(10);
    }

private:
    MarkerCallback  m_callback;
    std::thread     m_thread;
    volatile bool   m_quit {false};
};

void py_define_marker(pybind11::module& m)
{
    namespace py = pybind11;
    py::class_<PyMarker>(m, "Marker")
    .def( py::init< OrderId
                  , eSide
                  , double
                  , MarkerCallback const&
                  , PyBookPtr const&
                  > ()
                  , py::arg("cl_oid")
                  , py::arg("side")
                  , py::arg("price_delta")
                  , py::arg("callback")
                  , py::arg("books")
        )
    .def("stop",     &PyMarker::stop)
    .def("func_arg", &PyMarker::func_arg)
    //.def("best_bid_price",  &PyMarker::best_bid_price,  "!", py::arg("depth") = 0)
    ;

    py::enum_<eSide>(m, "eSide")
    .value("BID", eSide::BID)
    .value("ASK", eSide::ASK)
    .export_values();
}
