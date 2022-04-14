from market_py2cpp import Book, Marker

#eng = Engine(cpus=[3, 4, 5])

b1 = Book(market='BINANCE',  symbol='BTC_USDT' ) # potentially arbitraged
b2 = Book(market='BITFINEX', symbol='tBTCUSD' )

def on_marker(oid, market, symbol, px, qx):
    print('MARKER, CANCEL: %d px=%f qx=%f')

m1 = Marker(oid      = 12345678,
            bid      = True,
            trigger  = 0.0002,
            #books    = [b1,b3]
            )
#callback = on_marker,

def funky1(x):
    return x + 3

res = m1.func_arg(funky1)
print(f'RETURN: {res}')
