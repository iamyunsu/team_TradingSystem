#include <iostream>
#include <string>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../team_TradingSystem/StockAdapter.cpp"

using namespace testing;

TEST(testTradingSystem, 증권사_키워_로그인_성공) {
	KiwerAPI api;
	string id = "AAA";
	string pw = "BBB";

	std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
	std::ostringstream strCout;
	std::cout.rdbuf(strCout.rdbuf());

	api.login(id, pw);

	std::cout.rdbuf(oldCoutStreamBuf);

	string expected = id + " login success\n";
	EXPECT_THAT(strCout.str(), testing::StrEq(expected));
}

TEST(testTradingSystem, 증권사_네모_로그인_성공) {
	NemoAPI api;
	string id = "AAA";
	string pw = "BBB";

	std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
	std::ostringstream strCout;
	std::cout.rdbuf(strCout.rdbuf());

	api.certification(id, pw);

	std::cout.rdbuf(oldCoutStreamBuf);

	string expected = "[NEMO]" + id + " login GOOD\n";
	EXPECT_THAT(strCout.str(), testing::StrEq(expected));
}

TEST(testTradingSystem, 증권사_선택하지않고_로그인하면_실패) {
	EXPECT_EQ(1, 1);
}

TEST(testTradingSystem, 증권사_선택하고_로그인하지않고_buy하면_실패) {
	EXPECT_EQ(1, 1);
}

TEST(testTradingSystem, 증권사_선택하고_로그인하지않고_sell하면_실패) {
	EXPECT_EQ(1, 1);
}

TEST(testTradingSystem, 증권사_선택하고_로그인하지않고_getPrice하면_실패) {
	EXPECT_EQ(1, 1);
}

TEST(testTradingSystem, 키워에서_buy_성공) {
	EXPECT_EQ(1, 1);
}

TEST(testTradingSystem, 네모에서_buy_성공) {
	EXPECT_EQ(1, 1);
}

TEST(testTradingSystem, 키워에서_sell_성공) {
	EXPECT_EQ(1, 1);
}

TEST(testTradingSystem, 네모에서_sell_성공) {
	EXPECT_EQ(1, 1);
}

TEST(testTradingSystem, 키워에서_getPrice_성공) {
	EXPECT_EQ(1, 1);
}

TEST(testTradingSystem, 네모에서_getPrice_성공) {
	EXPECT_EQ(1, 1);
}

TEST(testTradingSystem, 키워에서_buyNiceTiming했는데_기준에맞지않아서_예외) {
	EXPECT_EQ(1, 1);
}

TEST(testTradingSystem, 네모에서_sellNiceTiming했는데_기준에맞지않아서_예외) {
	EXPECT_EQ(1, 1);
}