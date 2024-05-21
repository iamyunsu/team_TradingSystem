﻿#include <memory>
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
	void buy(int code, int price, int quantity) {
		stockBroker->buy(code, price, quantity);
	}
	void sell(int code, int price, int quantity) {
		stockBroker->sell(code, price, quantity);
	}
	int getPrice(int code) {
		stockBroker->getPrice(code);
	}

private:
	StockAdapter* stockBroker;
};
