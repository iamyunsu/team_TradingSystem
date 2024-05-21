#include <iostream>
#include <string>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../team_TradingSystem/AutoTradingSystem.cpp"

using namespace testing;

class MockDriver : public StockAdapter {
public:
	// StockAdapter을(를) 통해 상속됨
	MOCK_METHOD(void, login, (string, string), (override));
	MOCK_METHOD(void, buy, (string, int, int), (override));
	MOCK_METHOD(void, sell, (string, int, int), (override));
	MOCK_METHOD(int, getPrice, (string, int), (override));
};

class TestTradingSystemFixture : public Test {
	// Test을(를) 통해 상속됨
	void SetUp() override {
		std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
		std::cout.rdbuf(strCout.rdbuf());
	}
	void TearDown() override {
		std::cout.rdbuf(oldCoutStreamBuf);
	}

public:
	std::streambuf* oldCoutStreamBuf;
	std::ostringstream strCout;

	string id = "AAA";
	string pw = "BBB";
	string stock_code = "fake_code";

	KiwerStockAdapter kiwerStock;
	NemoStockAdapter nemoStock;
	AutoTradingSystem system{};
};
TEST_F(TestTradingSystemFixture, 증권사_키워_로그인_성공) {

	system.selectStockBrocker(&kiwerStock);
	system.login(id, pw);

	string expected = id + " login success\n";
	EXPECT_THAT(strCout.str(), testing::StrEq(expected));
}

TEST_F(TestTradingSystemFixture, 증권사_네모_로그인_성공) {
	system.selectStockBrocker(&nemoStock);
	system.login(id, pw);

	string expected = "[NEMO]" + id + " login GOOD\n";
	EXPECT_THAT(strCout.str(), testing::StrEq(expected));
}

TEST_F(TestTradingSystemFixture, 증권사_선택하지않고_로그인하면_실패) {
	EXPECT_EQ(1, 1);
}

TEST_F(TestTradingSystemFixture, 증권사_선택하고_로그인하지않고_buy하면_실패) {
	EXPECT_EQ(1, 1);
}

TEST_F(TestTradingSystemFixture, 증권사_선택하고_로그인하지않고_sell하면_실패) {
	EXPECT_EQ(1, 1);
}

TEST_F(TestTradingSystemFixture, 증권사_선택하고_로그인하지않고_getPrice하면_실패) {
	EXPECT_EQ(1, 1);
}

TEST_F(TestTradingSystemFixture, 키워에서_buy_성공) {
	KiwerAPI api;

	api.login(id, pw);

	std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
	std::ostringstream strCout;
	std::cout.rdbuf(strCout.rdbuf());

	api.buy("SEC", 1, 20);

	std::cout.rdbuf(oldCoutStreamBuf);

	string expected = "SEC : Buy stock ( 20 * 1)\n";
	EXPECT_THAT(strCout.str(), StrEq(expected));
}

TEST_F(TestTradingSystemFixture, 네모에서_buy_성공) {
	NemoAPI api;

	api.certification(id, pw);

	std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
	std::ostringstream strCout;
	std::cout.rdbuf(strCout.rdbuf());

	api.purchasingStock("SEC", 1, 20);

	std::cout.rdbuf(oldCoutStreamBuf);

	string expected = "[NEMO]SEC buy stock ( price : 1 ) * ( count : 20)\n";
	EXPECT_THAT(strCout.str(), StrEq(expected));
}

TEST_F(TestTradingSystemFixture, 키워에서_sell_성공) {
	KiwerAPI api;

	api.login(id, pw);

	std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
	std::ostringstream strCout;
	std::cout.rdbuf(strCout.rdbuf());

	api.sell("SEC", 1, 20);

	std::cout.rdbuf(oldCoutStreamBuf);

	string expected = "SEC : Sell stock ( 20 * 1)\n";
	EXPECT_THAT(strCout.str(), StrEq(expected));
}

TEST_F(TestTradingSystemFixture, 네모에서_sell_성공) {
	NemoAPI api;

	api.certification(id, pw);

	std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
	std::ostringstream strCout;
	std::cout.rdbuf(strCout.rdbuf());

	api.sellingStock("SEC", 1, 20);

	std::cout.rdbuf(oldCoutStreamBuf);

	string expected = "[NEMO]SEC sell stock ( price : 1 ) * ( count : 20)\n";
	EXPECT_THAT(strCout.str(), StrEq(expected));
}

TEST_F(TestTradingSystemFixture, 키워에서_getPrice_성공) {
	KiwerAPI api;

	api.login(id, pw);

	EXPECT_EQ(api.currentPrice("SEC"), 5400);
}

TEST_F(TestTradingSystemFixture, 네모에서_getPrice_성공) {
	AutoTradingSystem autoTrading;
	KiwerStockAdapter kiwerStock;
	autoTrading.selectStockBrocker(&kiwerStock);

	autoTrading.login(id, pw);
	
	EXPECT_THAT(autoTrading.getPrice("SEC", 10), 5300);
}


TEST_F(TestTradingSystemFixture, 증권사_선택_키워) {
	system.selectStockBrocker(&kiwerStock);
}

TEST_F(TestTradingSystemFixture, 증권사_선택_네모) {
	system.selectStockBrocker(&nemoStock);
}

TEST(testTradingSystem, buyNiceTiming_성공) {
	AutoTradingSystem autoTrading;
	MockDriver driver;
	autoTrading.selectStockBrocker(&driver);

	EXPECT_CALL(driver, getPrice)
		.WillOnce(Return(100))
		.WillOnce(Return(120))
		.WillOnce(Return(150));

	EXPECT_CALL(driver, buy)
		.Times(1);

	AutoTradingSystem system{};
	system.selectStockBrocker(&driver);
	system.buyNiceTiming("SEC", 3000);
}

TEST(testTradingSystem, sellNiceTiming_성공) {
	AutoTradingSystem autoTrading;
	MockDriver driver;
	autoTrading.selectStockBrocker(&driver);

	EXPECT_CALL(driver, getPrice)
		.WillOnce(Return(150))
		.WillOnce(Return(120))
		.WillOnce(Return(100));

	EXPECT_CALL(driver, sell)
		.Times(1);

	AutoTradingSystem system{};
	system.selectStockBrocker(&driver);
	system.sellNiceTiming("SEC", 3000);
}

