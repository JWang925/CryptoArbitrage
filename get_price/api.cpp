#include "api.h"

json::value get_trade_info(string const & SearchTerm){
    // Create http_client to send the request.
    http_client client(U("https://api.quadrigacx.com/v2/")); //construct an instance of http_client for quadriga.

    // Build request URI and start the request.
    uri_builder builder(U("/ticker")); //formulate request query
    builder.append_query(U("book"), U(SearchTerm)); //formulate request query
	//can use http_client_config to specify timeouts, proxies or credentials.
    client.request(methods::GET, builder.to_string()) //send the request
		.then([](http_response response)
		{
			//if status is good, extract
			if(response.status_code() == 200 )
			{
				cout <<"extracting JSON result..." <<endl;
				pplx::task<web::json::value> const v = response.extract_json();
				json::value const & result = v.get();	
				//print out bid & ask price for example
				if(!result.is_null())
				{
					cout << "timestamp:" << result.at("timestamp") <<endl;
					cout << "volume weighted 24h average:" << result.at("vwap") <<endl;
					cout << "current lowest ask price:"<< result.at("ask") <<endl;
					cout << "current highest bid price:"<< result.at("bid") <<endl; 
					//return result; 
				}
			}
		})
		.wait(); // Wait for all the outstanding I/O to complete

}

json::value get_order_book(string const & SearchTerm){
    // Create http_client to send the request.
    http_client client(U("https://api.quadrigacx.com/v2/")); //construct an instance of http_client for quadriga.

    // Build request URI and start the request.
    uri_builder builder(U("/order_book")); //formulate request query
    builder.append_query(U("book"), U(SearchTerm)); //formulate request query
	//can use http_client_config to specify timeouts, proxies or credentials.
    client.request(methods::GET, builder.to_string()) //send the request
		.then([](http_response response)
		{
			//if status is good, extract
			if(response.status_code() == 200 )
			{
				cout <<"extracting JSON result..." <<endl;
				pplx::task<web::json::value> const v = response.extract_json();
				json::value const & result = v.get();	
				//print out bid & ask price for example
				if(!result.is_null())
				{
					auto asks = result.at("asks");
					cout<<"lowerest ask:" << asks.at(0)<<endl;
					cout<<"lowerest ask price:" <<asks.at(0).at(0)<<endl;
					auto bid = result.at("bids");
					//return result;
				}
			}
		})
		.wait(); // Wait for all the outstanding I/O to complete

}




