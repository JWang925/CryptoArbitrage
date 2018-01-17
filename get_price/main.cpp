#include "api.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	json::value trade_info = get_trade_info("btc_cad");
	print_trade_info(trade_info);
	json::value order_book = get_order_book("btc_cad");
	print_order_book(order_book);
	return 0;
}
