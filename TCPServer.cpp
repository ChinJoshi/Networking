#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>

int main() {
	unsigned short int portNum = 3333;
	const int BacklogSize = 5;
	boost::asio::io_service IOService;
	const unsigned char messageSize = 7;
	char rawReadBuf[messageSize];
	boost::asio::ip::address IPAdress  = boost::asio::ip::address_v4::any();//Sets endpoint to listen from any IP
	boost::asio::ip::tcp::endpoint endpoint(IPAdress, portNum);//Creation of endpoint
	boost::asio::ip::tcp protocol = boost::asio::ip::tcp::v4();
	boost::asio::ip::tcp::acceptor acceptor(IOService, protocol);
	acceptor.bind(endpoint);
	acceptor.listen(BacklogSize);
	boost::asio::ip::tcp::socket socket(IOService);
	acceptor.accept(socket);
	boost::asio::read(socket, boost::asio::buffer(rawReadBuf,messageSize));
	std::string finalBuf=std::string(rawReadBuf);
	std::cout << finalBuf;
	return 0;
} 

