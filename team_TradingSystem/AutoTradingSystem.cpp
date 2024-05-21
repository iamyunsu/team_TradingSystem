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
	int getPrice(string code) {
		return stockBroker->getPrice(code);
	}
	void buyNiceTiming(string code, int price) {
		int firstPrice = getPrice(code);
		int secondPrice = getPrice(code);
		int thirdPrice = getPrice(code);
		if (firstPrice >= secondPrice || secondPrice >= thirdPrice) {
			return;
		}
		int quantity = price / thirdPrice;
		if (quantity > 0) {
			stockBroker->buy(code, thirdPrice, quantity);
		}
	}
	void sellNiceTiming(string code, int quantity) {
		int firstPrice = getPrice(code);
		int secondPrice = getPrice(code);
		int thirdPrice = getPrice(code);
		if (firstPrice <= secondPrice || secondPrice <= thirdPrice) {
			return;
		}
		stockBroker->sell(code, thirdPrice, quantity);
	}

private:
	StockAdapter* stockBroker;
};
