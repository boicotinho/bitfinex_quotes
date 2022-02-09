#include <pybind11/pybind11.h>
#include <bitfinex/market_data_feed.h>
#include <vector>
#include <stdio.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

class PyQuotes
{
public:
    PyQuotes(std::string const& symbol)
    {
        m_subscription.config.symbol = symbol;
    }

    void subscribe()
    {
        if(m_subscription.book_ptr)
            std::runtime_error("bitfinex_quotes Quotes book is already subscribed; "
                + m_subscription.config.symbol );

        if(!m_md_feed.is_started())
        {
            // fprintf(stderr, "Starting Bitfinex feed...\n");
            m_md_feed.start_recv_thread();
        }

        m_subscription.book_ptr = m_md_feed.subscribe(m_subscription.config);
        if(!m_subscription.book_ptr)
            std::runtime_error("bitfinex_quotes Quotes failed to subscribe; "
                + m_subscription.config.symbol );
    }

    void unsubscribe()
    {
        auto const chanId = safe_book().channel_id();
        m_md_feed.unsubscribe(chanId);
        m_subscription.book_ptr.reset();
    }

    bitfinex::level_based::px_t best_bid_price(uint32_t depth = 0) const
    {
        return safe_book().get_tob(depth).bid().price_level;
    }

    bitfinex::level_based::px_t best_ask_price(uint32_t depth = 0) const
    {
        return safe_book().get_tob(depth).ask().price_level;
    }

    bitfinex::qx_t best_bid_volume(uint32_t depth = 0) const
    {
        return safe_book().get_tob(depth).bid().total_qty;
    }

    bitfinex::qx_t best_ask_volume(uint32_t depth = 0) const
    {
        return safe_book().get_tob(depth).ask().total_qty;
    }

    std::string status(uint32_t depth = 0) const
    {
        return safe_book().get_tob(depth).to_string();
    }

private:

    const bitfinex::level_based::OrderBookP& safe_book() const
    {
        if(!m_subscription.book_ptr)
            std::runtime_error("bitfinex_quotes Quotes book is not yet subscribed; "
                + m_subscription.config.symbol);
        return *m_subscription.book_ptr;
    }

private:
    struct PySubscription
    {
        bitfinex::SubscriptionConfig config;
        bitfinex::OrderBookPPtr      book_ptr;
    };

private:
    PySubscription            m_subscription;
    bitfinex::MarketDataFeed  m_md_feed;
};


namespace py = pybind11;

PYBIND11_MODULE(bitfinex_quotes, m) {
    m.doc() = R"pbdoc(
        Bitfinex python binding
        -----------------------

        .. currentmodule:: bitfinex_quotes

        .. autosummary::
           :toctree: _generate

    )pbdoc";

    py::class_<PyQuotes>(m, "Quotes")
        .def(py::init<const std::string &>())
        .def("subscribe",       &PyQuotes::subscribe)
        .def("unsubscribe",     &PyQuotes::unsubscribe)
        .def("status",          &PyQuotes::status)

        .def("best_bid_price",  &PyQuotes::best_bid_price,  "!", py::arg("depth") = 0)
        .def("best_ask_price",  &PyQuotes::best_ask_price,  "!", py::arg("depth") = 0)
        .def("best_bid_volume", &PyQuotes::best_bid_volume, "!", py::arg("depth") = 0)
        .def("best_ask_volume", &PyQuotes::best_ask_volume, "!", py::arg("depth") = 0)

        ;

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
