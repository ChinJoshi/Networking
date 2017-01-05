#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <boost/asio.hpp>
#include <iostream>
#include <vector>



namespace net {

	class tcpCli {
	public:
		boost::asio::io_service io_service;
		boost::asio::ip::tcp::endpoint endpoint;
		int portNum;
		
		tcpCli(std::string rawIP,int preportNum) {
			std::cout << "CONSTRUCTOR STARTED" << std::endl;
			boost::asio::ip::address_v4 ip = boost::asio::ip::address_v4::from_string(rawIP);
			std::cout << "IP ADRESS OBJECT CREATED" << std::endl;
			boost::asio::ip::tcp::endpoint preEndpoint(ip,preportNum);
			std::cout << "RAW ENDPOINT CREATED" << std::endl;
			endpoint = preEndpoint;
			portNum = preportNum;
			std::cout << "FINAL ENDPOINT CREATED" << std::endl;
		}
	
		void sendString(std::string rawBuffer) {
			boost::system::error_code error;
			std::cout << "SEND FUNCTION STARTED" << std::endl;
			boost::asio::ip::tcp::socket socket(io_service);
			std::cout << "IO SERVICE OBJECT CREATED" << std::endl;
			socket.connect(endpoint,error);
			if (error) {
				std::cout << "AN ERROR OCCURED WHILE ATTEMPTING TO CONNECT THE SOCKET" << std::endl;
				std::cout << error.message() << std::endl;
			}
			else {
				std::cout << "SOCKET CONNECTED" << std::endl;
			}
			boost::asio::write(socket,boost::asio::buffer(rawBuffer),error);
			if (error) {
				std::cout << "AN ERROR OCCURED WHILE ATTEMPTING TO WRITE TO THE SOCKET" << std::endl;
			}
			else {
				std::cout << "BUFFER SUCCESFULLY WRITTEN TO SOCKET" << std::endl;
			}
		}
		void sendMat() {
			
		}
	};



	class tcpSer {
	public:
		boost::asio::io_service io_service;
		int portNum;
		tcpSer(int portNumly) {
			portNum = portNumly;
		}
		void recieveString() {
			//std::vector<char> buffer;
			std::vector <char> buffer(128);
			boost::asio::ip::tcp::socket socket(io_service);
			boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address_v4::any(), portNum);
			boost::asio::ip::tcp::acceptor acceptor(io_service, endpoint.protocol());
			acceptor.bind(endpoint);
			std::cout << "ACCEPTOR HAS BOUND TO ENDPOINT" << std::endl;
			acceptor.listen();
			std::cout << "ACCEPTOR IS LISTENING" << std::endl;
			acceptor.accept(socket);
			std::cout << "ACCEPTOR HAS ACCEPTED A CONNECTION" << std::endl;
			socket.receive(boost::asio::buffer(buffer));
			std::cout << "READING FROM SOCKET TO BUFFER" << std::endl;
			//std::string stringBuf = std::string(buffer.begin(), buffer.end());
			std::string stringBuf = std::string(buffer.begin(),buffer.end());
			std::cout << "CONVERTING BUFFER TO STRING" << std::endl;
			std::cout << "PRINTING BUFFER" << std::endl;
			std::cout << "RECIEVED MESSAGE: "<<stringBuf << std::endl;
			std::cout << "PRINTING BUFFER" << std::endl;
		}
		
	};



	class udpCli {

	};

	class udpSer {

	};
}
