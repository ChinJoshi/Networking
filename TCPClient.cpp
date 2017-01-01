#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>

int main() {
	
	std::string rawIP = "123.123.123";
	unsigned short int portNum = 3333;
	boost::asio::io_service ioService;
	std::string rawBuffer = "Here goes the message to send";
	std::size_t bytes_written = 0;
	//Everything below this comment to the next comment is for creating an endpoint in a clinet situation to specify the server to communicate with
	boost::asio::ip::address ipAddress = boost::asio::ip::address::from_string(rawIP);
	boost::asio::ip::tcp::endpoint endpoint(ipAddress, portNum);
	//Everything below this comment to the next comment is for creating and opening an active socket
	boost::asio::ip::tcp protocol = boost::asio::ip::tcp::v4();
	boost::asio::ip::tcp::socket socket(ioService);
	socket.open(protocol);
	socket.connect(endpoint);
	//Everything below this comment to the next comment is for converting the string to a fixed ength buffer that can be used to write to sockets in asio
	boost::asio::const_buffers_1 finalBuffer = boost::asio::buffer(rawBuffer);
	//Everything below this comment to the next comment is for writing to the socket
	boost::asio::write(socket, finalBuffer);
	return 0;
}