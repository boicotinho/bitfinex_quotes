#include <pybind11/pybind11.h>
#include "version.h"

namespace py = pybind11;

void py_define_quotes(py::module&);
void py_define_book(py::module&);
void py_define_marker(py::module&);

PYBIND11_MODULE(market_py2cpp, m)
{
    m.doc() = R"pbdoc(
        Sparkland python/c++ binding
        -----------------------

        .. currentmodule:: market_py2cpp

        .. autosummary::
           :toctree: _generate

    )pbdoc";

    py_define_quotes(m);
    py_define_book(m);
    py_define_marker(m);

    m.attr("__version__") = VERSION_CSTRING;
}
