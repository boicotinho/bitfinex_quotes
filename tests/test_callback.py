import market_py2cpp as cpp
import time

#eng = Engine(cpus=[3, 4, 5])

b1 = cpp.Book(market='BINANCE',  symbol='BTC_USDT' ) # potentially arbitraged
b2 = cpp.Book(market='BITFINEX', symbol='tBTCUSD' )

def on_marker(cl_oid, side, market, symbol, px, qx):
    print('MARKER, CANCEL: %d px=%f qx=%f')
    # Cancel the order via python...

m1 = cpp.Marker(cl_oid      = 12345678,
                side        = cpp.BID,
                price_delta = 0.0002,
                callback    = on_marker,
                books       = [b1,b2]
                )

for _ in range(10):
    time.sleep(1)
    print('======')

m1.stop()
