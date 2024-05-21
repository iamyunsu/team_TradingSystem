#include <memory>
#include <string>
#include "StockAdapter.cpp"

class AutoTradingSystem {
public:
	void selectStockBrocker(StockAdapter* stockAdapter) {
		stockBroker = stockAdapter;
	}

private:
	StockAdapter* stockBroker;
};
