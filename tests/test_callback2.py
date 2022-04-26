import market_py2cpp as cpp
import time

#eng = Engine(cpus=[3, 4, 5])

def on_ticker(px, qx, market, symbol):
    pass 

def on_marker(cl_oid, side, market, symbol, px, qx):
    print('MARKER, CANCEL: %d px=%f qx=%f') # Cancel the order via python... 


b1 = cpp.Book(market='BINANCE',  symbol='BTC_USDT', callback=on_ticker ) # potentially arbitraged
b2 = cpp.Book(market='BITFINEX', symbol='tBTCUSD',  callback=on_ticker)

b3 = cpp.FungibleBook(markets=['BINANCE', 'BITFINEX'], fungible='BTCxUSD', cb_ticker, cb_marker)

m1 = cpp.Marker(cl_oid      = 12345678,
                side        = cpp.BID,
                price_delta = 0.0002,
                callback    = on_marker,
                books       = [b1,b2] # added to both books, cl_oid potentially called once for each book
                )

for _ in range(10):
    time.sleep(1)
    print('======')

m1.stop()
