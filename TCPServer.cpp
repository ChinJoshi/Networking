#include <boost/asio.hpp>

int main() {
	unsigned short int portNum = 3333;
	const int BacklogSize = 5;
	const size_t BufferSize = 20;
	boost::asio::io_service IOService;
	boost::asio::ip::address IPAdress  = boost::asio::ip::address_v4::any();//Sets endpoint to listen from any IP
	boost::asio::ip::tcp::endpoint endpoint(IPAdress, portNum);//Creation of endpoint
	boost::asio::ip::tcp protocol = boost::asio::ip::tcp::v4();
	boost::asio::ip::tcp::acceptor acceptor(IOService, protocol);
	acceptor.bind(endpoint);
	acceptor.listen(BacklogSize);
	boost::asio::ip::tcp::socket socket(IOService);
	acceptor.accept(socket);
	std::unique_ptr<char[]> buf(new char[BufferSize]);
	boost::asio::mutable_buffers_1 InputBuffer = boost::asio::buffer(static_cast<void*>(buf.get()),BufferSize);
	boost::asio::read(socket, InputBuffer);
}