#include <boost/asio.hpp>

#include <iostream>

int main() {
	unsigned short int portNum = 2667;
	boost::asio::io_service io_service;
	const unsigned char messageSize =2;
	char rawReadBuf[2];
	try {

		boost::asio::ip::tcp::socket socket(io_service);

		boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address_v4::any(), portNum);

		boost::asio::ip::tcp::acceptor acceptor(io_service, endpoint.protocol());

		acceptor.bind(endpoint);
		std::cout << "ACCEPTOR HAS BOUND TO ENDPOINT" << std::endl;

		acceptor.listen(5);
		std::cout << "ACCEPTOR IS LISTENING" << std::endl;

		acceptor.accept(socket);
		std::cout << "ACCEPTOR HAS ACCEPTED A CONNECTION" << std::endl;

		boost::asio::read(socket, boost::asio::buffer(rawReadBuf));
		std::cout << "READING FROM SOCKET TO BUFFER" << std::endl;

		std::string finalBuf = std::string(rawReadBuf);
		std::cout << "CONVERTING BUFFER TO STRING" << std::endl;
		std::cout << "PRINTING BUFFER" << std::endl;
		std::cout << finalBuf<<std::endl;
		std::cout << "PRINTING BUFFER" << std::endl;
	}
	catch (boost::system::system_error &e) {     
		std::cout << "Error occured!"<< std::endl;
		std::cout<<e.code()<< "      Message: " << e.what();
	}
	system("PAUSE");
	return 0;

}

