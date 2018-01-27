
#include <string>
#include <iostream>
#include "quadriga.h"
#include "kraken.h"

using namespace std;

double EqCqBqE(); //return profitability of Ethereum (through Quadriga) to Canadian Dollar (through Quadriga) to Bitcoin to Ethereum
double EqBqCqE(); //return profitability of Ethereum (through Quadriga)to Canadian Dollar (through Quadriga) to Bitcoin to Ethereum
double EqBtBkE(); //return profitability of Ethereum (through Quadriga) to BTC (transfer to Kraken) to BTC (through Kraken) to Ethereum

int main(int argc, char* argv[])
{
	//cout << "margin of EqCqBqE is (without fee):" << EqCqBqE() << "%" << endl;

	//cout << "margin of EqBqCqE is (without fee):" << EqBqCqE() << "%" << endl;

	cout << "margin of EqBtBkE is (without fee):" << EqBtBkE() << "%" << endl;



//	Kraken k;
//	json::value order_book = k.get_order_book("ethcad");
//	k.print_order_book(order_book);
//	cout << k.get_ask(order_book) << endl;
//	cout << k.get_bid(order_book) << endl;



	return 0;
}


double EqCqBqE(){
	double asset=100;

	Quadriga q; //start an instance of q
	json::value eth_cad_order = q.get_order_book("eth_cad");  // bid: eth -> cad; ask: cad -> eth
	asset = asset * q.get_bid(eth_cad_order);//now asset is in CAD
	q.print_order_book(eth_cad_order);
	cout << "asset:" <<asset << endl;

	json::value btc_cad_order = q.get_order_book("btc_cad"); // bid: btc -> cad; ask: cad -> btc
	asset = asset / q.get_ask(btc_cad_order); //now asset is in btc
	q.print_order_book(btc_cad_order);
	cout << "asset:" <<asset << endl;

	json::value eth_btc_order = q.get_order_book("eth_btc"); // bid: eth -> btc; ask: btc -> eth
	asset = asset / q.get_ask(eth_btc_order); //now asset is in eth
	q.print_order_book(eth_btc_order);
	cout << "asset:" <<asset << endl;

	double margin = asset-100;

	return margin;
}


double EqBqCqE(){
	double asset=100;

	Quadriga q; //start an instance of q
	json::value eth_btc_order = q.get_order_book("eth_btc"); // bid: eth -> btc; ask: btc -> eth
	asset = asset * q.get_bid(eth_btc_order); //now asset is in bitcoin
	q.print_order_book(eth_btc_order);
	cout << "asset:" <<asset << endl;

	json::value btc_cad_order = q.get_order_book("btc_cad"); // bid: btc -> cad; ask: cad -> btc
	asset = asset * q.get_bid(btc_cad_order); //now asset is in CAD
	q.print_order_book(btc_cad_order);
	cout << "asset:" <<asset << endl;

	json::value eth_cad_order = q.get_order_book("eth_cad");  // bid: eth -> cad; ask: cad -> eth
	asset = asset / q.get_ask(eth_cad_order);//now asset is in ethereum
	q.print_order_book(eth_cad_order);
	cout << "asset:" <<asset << endl;

	double margin = asset-100;

	return margin;
}

double EqBtBkE(){
	double asset=100;

	Quadriga q; //start an instance of q
	json::value eth_btc_order = q.get_order_book("eth_btc"); // bid: eth -> btc; ask: btc -> eth
	asset = asset * q.get_bid(eth_btc_order); //now asset is in bitcoin
	q.print_order_book(eth_btc_order);
	cout << "asset:" <<asset << endl;

	Kraken k;
	json::value eth_xbt_order = k.get_order_book("ETHXBT");  // bid: eth -> cad; ask: cad -> eth
	asset = asset / k.get_ask(eth_xbt_order);//now asset is in ethereum
	k.print_order_book(eth_xbt_order);
	cout << "asset:" <<asset << endl;

	double margin = asset-100;

	return margin;
}

