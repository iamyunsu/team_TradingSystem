#include <iostream>
#include "KiwerAPI.cpp"
#include "NemoAPI.cpp"

using namespace std;

class StockAdapter {
	virtual void login(string id, string pass) = 0;
	virtual void buy(string code, int price, int quantity) = 0;
	virtual void sell(string code, int price, int quantity) = 0;
	virtual int getPrice(string code) = 0;
};

class NemoStockAdapter : public StockAdapter {
public:
	void login(string id, string password)
	{
		api.certification(id, password);
	}
	void buy(string code, int price, int quantity)
	{
		api.purchasingStock(code, price, quantity);
	}
	void sell(string code, int price, int quantity)
	{
		api.sellingStock(code, price, quantity);
	}
	int getPrice(string code)
	{
		return api.getMarketPrice(code, 1);
	}
private:
	NemoAPI api;

};

class KiwerStockAdapter : public StockAdapter {
public:
	void login(string id, string password)
	{
		api.login(id, password);
	}
	void buy(string code, int price, int quantity)
	{
		api.buy(code, quantity, price);
	}
	void sell(string code, int price, int quantity)
	{
		api.sell(code, quantity, price);
	}
	int getPrice(string code)
	{
		return api.currentPrice(code);
	}

private:
	KiwerAPI api;

};
