#include <memory>
#include <string>
#include "StockAdapter.cpp"

class AutoTradingSystem {
public:
	void selectStockBrocker(StockAdapter* stockAdapter) {
		stockBroker = stockAdapter;
	}
	void login(string id, string pass) {
		stockBroker->login(id, pass);
	}
	void buy(string code, int price, int quantity) {
		stockBroker->buy(code, price, quantity);
	}
	void sell(string code, int price, int quantity) {
		stockBroker->sell(code, price, quantity);
	}
	int getPrice(string code, int minute = 0) {
		return stockBroker->getPrice(code, minute);
	}

private:
	StockAdapter* stockBroker;
};
