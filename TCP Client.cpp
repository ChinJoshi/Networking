#include <boost/asio.hpp>
#include <iostream>


int main() {
	std::string rawIP = "127.0.0.1";
	unsigned short int portNum = 2667;
	boost::asio::io_service ioService;
	unsigned char rawBuffer[] = { '1','2'};
	boost::system::error_code ec;
	//Everything below this comment to the next comment is for creating an endpoint in a clinet situation to specify the server to communicate with
	boost::asio::ip::address ipAddress = boost::asio::ip::address::from_string(rawIP);
	boost::asio::ip::tcp::endpoint endpoint(ipAddress, portNum);
	//Everything below this comment to the next comment is for creating and opening an active socket
	boost::asio::ip::tcp::socket socket(ioService);
	socket.connect(endpoint, ec);
	if (ec) {
		std::cout << "AN ERROR HAS OCCURED!!!" << std::endl;
		std::cout << ec.message() << std::endl;;
	}
	else {
		std::cout << "NO ERRORS HAVE OCCURED YET" << std::endl;
		std::cout << "BUFFER CREATED" << std::endl;
		boost::asio::write(socket, boost::asio::buffer(rawBuffer));
		std::cout << "MESSAGE HAS BEEN WRITTEN TO SOCKET" << std::endl;
	}
	system("PAUSE");
	return 0;
}
