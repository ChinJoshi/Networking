#include <boost/asio.hpp>
#include <boost/array.hpp>


int submain() {
	boost::asio::io_service io_service;
	boost::asio::ip::udp::socket socket(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 13));
	for (;;)
	{
		boost::array<char, 1> recieved;
		boost::asio::ip::udp::endpoint destination(boost::asio::ip::address::from_string("John's IP Goes Here"),1234);
		socket.receive_from(boost::asio::buffer(recieved), destination, 13);
		std::string message = "Bill Please";
		socket.send_to(boost::asio::buffer(message), destination, 0);
	}
}