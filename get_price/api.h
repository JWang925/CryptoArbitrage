#ifndef api_h
#define api_h
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>

#include <iostream>
#include <string>

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

using namespace std;

json::value get_trade_info(string const & SearchTerm); //ping Quadriga and get the trade info

json::value get_order_book(string const & SearchTerm);

void print_trade_info(json::value trade_info);

void print_order_book(json::value order_book);

#endif

