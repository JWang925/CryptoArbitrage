#include "kraken.h"
#include <iomanip>

json::value Kraken::get_order_book(string const & SearchTerm){
	// Create http_client to send the request.
	http_client client(U("https://api.kraken.com/0/public/")); //construct an instance of http_client for quadriga.

	// Build request URI and start the request.
	uri_builder builder(U("/Depth")); //formulate request query
	builder.append_query(U("pair"), U(SearchTerm)); //formulate request query
	builder.append_query(U("count"), U(5)); //formulate request query
	//can use http_client_config to specify timeouts, proxies or credentials.

	json::value result;
	client.request(methods::GET, builder.to_string()) //send the request
		.then(
			[&](http_response response){
				//cout << "response code: " << response.status_code() << endl;
				if(response.status_code() == 200 ) //if status is good, extract
				{
					//cout <<"extracting JSON result..." <<endl;
					pplx::task<json::value> const v = response.extract_json();
					result = v.get();	
				}
			}
		)
		.wait(); // Wait for all the outstanding I/O to complete	
		return result; 	
}

void Kraken::print_order_book(json::value order_book){
	if(order_book.is_null()){
		cout << "print input is null" <<endl;
	}
	if(!order_book.is_null()){
		cout << "Kraken market-----------------------" << endl;
		//cout << "number of trade pairs:" <<order_book.at("result").size() <<endl;

		json::object result = order_book.at("result").as_object();
		for (auto iter = result.cbegin(); iter != result.cend(); ++iter){
			cout << "trade pair:" << iter->first << endl;
			auto asks = iter->second.at("asks");
			auto bids = iter->second.at("bids");
			cout<< setw(30) << "lowerest ask/quantity:" << setw(30) << "highest bid/quantity:" <<endl;
			cout<< setw(30) << asks.at(0) << setw(30) << bids.at(0) <<endl;
			//cout<< setw(30) << asks.at(1) << setw(30) << bids.at(1) <<endl;
			//cout<< setw(30) << asks.at(2) << setw(30) << bids.at(2) <<endl;
		}
	}
}

double Kraken::get_ask(json::value order_book){ //get lowest ask price from order book
	json::object result = order_book.at("result").as_object();
	auto iter = result.cbegin(); 
	auto asks = iter->second.at("asks");
	string lowest_ask_str=asks.at(0).at(0).as_string();
	return string_to_double (lowest_ask_str);
}

double Kraken::get_bid(json::value order_book){ //get highest bid price from order book
	json::object result = order_book.at("result").as_object();
	auto iter = result.cbegin(); 
	auto bids = iter->second.at("bids");
	string highest_bid_str=bids.at(0).at(0).as_string();
	return string_to_double (highest_bid_str);
}
