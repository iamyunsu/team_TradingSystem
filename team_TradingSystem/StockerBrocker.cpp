class StockerBrocker {
public:
	virtual void selectStockBrocker() = 0;
	virtual void login() = 0;
	virtual void buy() = 0;
	virtual void sell() = 0;
	virtual void getPrice() = 0;
};