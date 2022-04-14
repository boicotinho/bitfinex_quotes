from market_py2cpp import Quotes # this should be implemented in C++
import time

def test_main():
    quotes = Quotes("BTCUSD")
    quotes.subscribe()
    for _ in range(10):
        time.sleep(1)
        print(quotes.status())
        print('best_bid ', quotes.best_bid_price())
        print('best_ask ', quotes.best_ask_price())
        print('best_bid ', quotes.best_bid_volume())
        print('best_ask ', quotes.best_ask_volume())

    quotes.unsubscribe()
