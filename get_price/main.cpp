#include "api.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	auto trade_info = get_trade_info("btc_cad");
	auto order_book = get_order_book("btc_cad");
	return 0;
}
