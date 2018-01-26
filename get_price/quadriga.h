#ifndef quadriga_h
#define quadriga_h
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>

#include <iostream>
#include <string>

#include "aux.h"

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

using namespace std;



class Quadriga
{
public:
json::value get_trade_info(string const & SearchTerm); // get the trade info like ask/bid/volume 

json::value get_order_book(string const & SearchTerm); //get detailed order book

void print_trade_info(json::value trade_info); // print trade info

void print_order_book(json::value order_book); // print order book

double get_spread(json::value order_book); //calculate spread from order book

double get_ask(json::value order_book); //get lowest ask price from order book

double get_bid(json::value order_book); //get highest bid price from order book
};

#endif

