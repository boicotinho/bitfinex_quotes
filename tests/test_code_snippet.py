from bitfinex_quotes import Quotes # this should be implemented in C++
import time

quotes = Quotes("BTCUSD")
quotes.subscribe()
for _ in range(10):
    time.sleep(1)
    print('best_bid ', quotes.best_bid_price())
    print('best_ask ', quotes.best_ask_price())
    print('best_bid ', quotes.best_bid_volume())
    print('best_ask ', quotes.best_ask_volume())

quotes.unsubscribe()
