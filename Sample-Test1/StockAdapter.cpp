#include <iostream>
#include "../team_TradingSystem/KiwerAPI.cpp"
#include "../team_TradingSystem/NemoAPI.cpp"

using namespace std;

class StockAdapter {
	virtual void login(string id, string pass) = 0;
	virtual void buy(int code, int price, int quantity) = 0;
	virtual void sell(int code, int price, int quantity) = 0;
	virtual int getPrice(int code) = 0;
};

class NemoStockAdapter : public StockAdapter {
public:
	void login(string id, string pass)
	{

	}
	void buy(int code, int price, int quantity)
	{

	}
	void sell(int code, int price, int quantity)
	{

	}
	int getPrice(int code)
	{

	}
private:
	NemoAPI api;

};

class KiwerStockAdapter : public StockAdapter {
public:
	void login(string id, string pass)
	{

	}
	void buy(int code, int price, int quantity)
	{

	}
	void sell(int code, int price, int quantity)
	{

	}
	int getPrice(int code)
	{

	}

private:
	KiwerAPI api;

};
