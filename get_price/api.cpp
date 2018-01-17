#include "api.h"

json::value get_trade_info(string const & SearchTerm){
    // Create http_client to send the request.
    http_client client(U("https://api.quadrigacx.com/v2/")); //construct an instance of http_client for quadriga.

    // Build request URI and start the request.
    uri_builder builder(U("/ticker")); //formulate request query
    builder.append_query(U("book"), U(SearchTerm)); //formulate request query
	//can use http_client_config to specify timeouts, proxies or credentials.

	json::value result;
    client.request(methods::GET, builder.to_string()) //send the request
		.then(
			[&](http_response response){
				cout << "response code: " << response.status_code() << endl;
				if(response.status_code() == 200 ) //if status is good, extract
				{
					cout <<"extracting JSON result..." <<endl;
					pplx::task<json::value> const v = response.extract_json();
					result = v.get();	
				}
			}
		)
		.wait(); // Wait for all the outstanding I/O to complete	
		return result; 	
}

json::value get_order_book(string const & SearchTerm){
    // Create http_client to send the request.
    http_client client(U("https://api.quadrigacx.com/v2/")); //construct an instance of http_client for quadriga.

    // Build request URI and start the request.
    uri_builder builder(U("/order_book")); //formulate request query
    builder.append_query(U("book"), U(SearchTerm)); //formulate request query
	//can use http_client_config to specify timeouts, proxies or credentials.

	json::value result;
    client.request(methods::GET, builder.to_string()) //send the request
		.then(
			[&](http_response response){
				if(response.status_code() == 200 ) 		//if status is good, extract
				{
					cout <<"extracting JSON result..." <<endl;
					pplx::task<web::json::value> const v = response.extract_json();
					result = v.get();	
				}
			}
		)
		.wait(); // Wait for all the outstanding I/O to complete
		return result; 
}

void print_trade_info(json::value trade_info){
	if(!trade_info.is_null()){
		cout << "timestamp:" << trade_info.at("timestamp") <<endl;
		cout << "volume weighted 24h average:" << trade_info.at("vwap") <<endl;
		cout << "current lowest ask price:"<< trade_info.at("ask") <<endl;
		cout << "current highest bid price:"<< trade_info.at("bid") <<endl; 
	}
}

void print_order_book(json::value order_book){
	if(order_book.is_null()){
		cout << "print input is null" <<endl;
	}
	if(!order_book.is_null()){
		auto asks = order_book.at("asks");
		cout<<"lowerest ask:" <<endl;
		cout<< asks.at(0)<<endl;
		cout<< asks.at(1)<<endl;
		cout<< asks.at(2)<<endl;
		auto bids = order_book.at("bids");
		cout<<"highest bid:" <<endl;
		cout<< bids.at(0)<<endl;
		cout<< bids.at(1)<<endl;
		cout<< bids.at(2)<<endl;
	} 
}




