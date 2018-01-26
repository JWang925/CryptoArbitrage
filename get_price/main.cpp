
#include <string>
#include <iostream>
#include "quadriga.h"
#include "kraken.h"

using namespace std;

double ECBE(); //return profitability of Ethereum to Canadian Dollar to Bitcoin to Ethereum
double EBCE(); //return profitability of Ethereum to Canadian Dollar to Bitcoin to Ethereum


int main(int argc, char* argv[])
{
	cout << "margin of ECBE is:" << ECBE() << "%" << endl;

	cout << "margin of EBCE is:" << EBCE() << "%" << endl;

// Test cases.
/*
	json::value order_book = get_order_book("btc_cad");
	print_order_book(order_book);
	
	double spread = get_spread(order_book);
	cout << "spread is:" << spread << endl;

	double bid = get_bid(order_book);
	cout << "bid is:" << bid << endl;

	double ask = get_ask(order_book);
	cout << "ask is:" << ask << endl;
*/

	return 0;
}


double ECBE(){
	double asset=100;

	Quadriga q; //start an instance of q
	json::value eth_cad_order = q.get_order_book("eth_cad");  // bid: eth -> cad; ask: cad -> eth
	asset = asset * q.get_bid(eth_cad_order);//now asset is in CAD
	q.print_order_book(eth_cad_order);
	cout << asset << endl;

	json::value btc_cad_order = q.get_order_book("btc_cad"); // bid: btc -> cad; ask: cad -> btc
	asset = asset / q.get_ask(btc_cad_order); //now asset is in btc
	q.print_order_book(btc_cad_order);
	cout << asset << endl;

	json::value eth_btc_order = q.get_order_book("eth_btc"); // bid: eth -> btc; ask: btc -> eth
	asset = asset / q.get_ask(eth_btc_order); //now asset is in eth
	q.print_order_book(eth_btc_order);
	cout << asset << endl;

	double margin = asset-100;

	return margin;
}


double EBCE(){
	double asset=100;

	Quadriga q; //start an instance of q
	json::value eth_btc_order = q.get_order_book("eth_btc"); // bid: eth -> btc; ask: btc -> eth
	asset = asset * q.get_bid(eth_btc_order); //now asset is in bitcoin
	q.print_order_book(eth_btc_order);
	cout << asset << endl;

	json::value btc_cad_order = q.get_order_book("btc_cad"); // bid: btc -> cad; ask: cad -> btc
	asset = asset * q.get_bid(btc_cad_order); //now asset is in CAD
	q.print_order_book(btc_cad_order);
	cout << asset << endl;

	json::value eth_cad_order = q.get_order_book("eth_cad");  // bid: eth -> cad; ask: cad -> eth
	asset = asset / q.get_ask(eth_cad_order);//now asset is in ethereum
	q.print_order_book(eth_cad_order);
	cout << asset << endl;

	double margin = asset-100;

	return margin;
}
