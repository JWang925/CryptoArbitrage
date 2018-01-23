#include "api.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	json::value order_book = get_order_book("btc_cad");
	print_order_book(order_book);
	
	double spread = get_spread(order_book);
	cout << "spread is:" << spread << endl;


	return 0;
}
