#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>

int main() {
	std::string rawIP = "192.168.1.252";
	unsigned short int portNum = 2667;
	boost::asio::io_service ioService;
	std::string rawBuffer = "ABCD";
	boost::system::error_code ec;
	//Everything below this comment to the next comment is for creating an endpoint in a clinet situation to specify the server to communicate with
	boost::asio::ip::address ipAddress = boost::asio::ip::address::from_string(rawIP);
	boost::asio::ip::tcp::endpoint endpoint(ipAddress, portNum);
	//Everything below this comment to the next comment is for creating and opening an active socket
	boost::asio::ip::tcp::socket socket(ioService);
	for (;;) {
		socket.connect(endpoint, ec);
		if (ec) {
			std::cout << ec.message();
			system("PAUSE");
			break;
		}
		//Everything below this comment to the next comment is for converting the string to a fixed ength buffer that can be used to write to sockets in asio
		boost::asio::const_buffers_1 finalBuffer = boost::asio::buffer(rawBuffer);
		//Everything below this comment to the next comment is for writing to the socket
		boost::asio::write(socket, finalBuffer);
	}
	return 0;
}
