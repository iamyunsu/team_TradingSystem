#include <iostream>
#include "KiwerAPI.cpp"
#include "NemoAPI.cpp"

using namespace std;

class StockAdapter {
public:
	virtual void login(string id, string pass) = 0;
	virtual void buy(string code, int price, int quantity) = 0;
	virtual void sell(string code, int price, int quantity) = 0;
	virtual int getPrice(string code) = 0;
};

class NemoStockAdapter : public StockAdapter {
public:
	void login(string id, string password) override
	{
		api.certification(id, password);
	}
	void buy(string code, int price, int quantity) override
	{
		api.purchasingStock(code, price, quantity);
	}
	void sell(string code, int price, int quantity) override
	{
		api.sellingStock(code, price, quantity);
	}
	int getPrice(string code) override
	{
		return api.getMarketPrice(code, 1);
	}
private:
	NemoAPI api;

};

class KiwerStockAdapter : public StockAdapter {
public:
	void login(string id, string password) override
	{
		api.login(id, password);
	}
	void buy(string code, int price, int quantity) override
	{
		api.buy(code, quantity, price);
	}
	void sell(string code, int price, int quantity) override
	{
		api.sell(code, quantity, price);
	}
	int getPrice(string code) override
	{
		return api.currentPrice(code);
	}

private:
	KiwerAPI api;

};
