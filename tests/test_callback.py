from market_py2cpp import Book, Marker
import time

#eng = Engine(cpus=[3, 4, 5])

b1 = Book(market='BINANCE',  symbol='BTC_USDT' ) # potentially arbitraged
b2 = Book(market='BITFINEX', symbol='tBTCUSD' )

def on_marker(oid, market, symbol, px, qx):
    print('MARKER, CANCEL: %d px=%f qx=%f')

m1 = Marker(oid      = 12345678,
            bid      = True,
            trigger  = 0.0002,
            callback = on_marker,
            #books    = [b1,b3]
            )

for _ in range(10):
    time.sleep(1)
    print('======')

m1.stop()
