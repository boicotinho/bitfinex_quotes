#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <marketlinks/bitfinex/market_data_feed.h>
#include <vector>
#include <thread>
#include <functional>
#include <stdio.h>

using OrderId        = uint64_t;
using MarkerCallback = std::function<int(int)>;

class PyMarker
{
public:
    PyMarker( OrderId        const  a_oid
            , bool           const  a_bid
            , double         const  a_trigger
            , MarkerCallback const& a_callback
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
                  , bool
                  , double
                  , MarkerCallback const&
                  > ()
                  , py::arg("oid")
                  , py::arg("bid")
                  , py::arg("trigger")
                  , py::arg("callback")
                  )
    .def("stop",     &PyMarker::stop)
    .def("func_arg", &PyMarker::func_arg)
    //.def("best_bid_price",  &PyMarker::best_bid_price,  "!", py::arg("depth") = 0)
    ;
}
