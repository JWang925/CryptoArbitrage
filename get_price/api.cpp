#include "api.h"

void print_result(json::value const & value)
{
	if(!value.is_null())
	{
		auto ask = value.at("ask");
		auto bid = value.at("bid");
		cout << "ask price"<< ask <<endl;
		cout << "bid price"<< bid <<endl; 
	}

}

void get_price_Q(string const & SearchTerm){

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
				cout <<"extracting JSON..." <<endl;
				pplx::task<web::json::value> const v = response.extract_json();
				json::value const & v2 = v.get();
				print_result(v2);
			}
		})
		.wait();
    // Wait for all the outstanding I/O to complete and handle any exceptions
}




