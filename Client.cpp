#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>


int main() {
	boost::asio::io_service io_service;
	boost::asio::ip::udp::resolver resolver(io_service);	boost::asio::ip::udp::resolver::query query(boost::asio::ip::udp::v4(), "localhost", "daytime");
	boost::asio::ip::udp::endpoint endpoint = *resolver.resolve(query);
	boost::asio::ip::udp::socket socket(io_service);
	socket.open(boost::asio::ip::udp::v4());
	std::string send_buf = "wut";
	socket.send_to(boost::asio::buffer(send_buf), endpoint);
}