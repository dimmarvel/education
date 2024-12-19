#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <netinet/in.h>

std::string uint8_to_hex_string(const uint8_t *data, size_t size) {
	std::stringstream ss;
	ss << std::hex << std::setfill('0');
	for (size_t i = 0; i < size; i++) {
		ss << std::setw(2) << static_cast<int>(data[i]);
		if (i % 2 != 0) ss << " ";
		if (i % 16 == 15) ss << "\n";
	}
	return ss.str();
}
// 0000   00 00 ff fe 00 00 00 00 00 00 00 00 00 00 08 00
// 0010   45 00 00 34 3b 3b 40 00 3f 06 91 ad 34 22 30 aa
// 0020   0a 0e 00 02 01 bb d0 b0 15 73 67 ed 74 40 a7 32
// 0030   80 10 00 3f 5f 91 00 00 01 01 08 0a 9a 7a b8 d3
// 0040   2a e3 be a0

// 0000   00 00 ff fe 00 00 00 00 00 00 00 00 00 00 08 00   ................
// 0010   45 00 00 34 3b 3b 40 00 3f 06 91 ad 34 22 30 aa   E..4;;@.?...4"0.
// 0020   0a 0e 00 02 01 bb d0 b0 15 73 67 ed 74 40 a7 32   .........sg.t@.2
// 0030   80 10 00 3f 5f 91 00 00 01 01 08 0a 9a 7a b8 d3   ...?_........z..
// 0040   2a e3 be a0                                       *...
//"39","4.211716785","52.34.48.170","10.14.0.2","TCP","68",
//"[TCP ACKed unseen segment] 443 → 53424 [ACK] Seq=1 Ack=2 Win=63 Len=0 TSval=2591733971 TSecr=719568544"

struct tcp_packet_header
{
	uint16_t source_port;
	uint16_t dest_port;
	
	uint32_t seq_number;
	
	uint32_t ack_number;

	uint16_t res1:4,
			doff:4,
			fin:1,
			syn:1,
			rst:1,
			psh:1,
			ack:1,
			urg:1,
			ece:1,
			cwr:1;
	uint16_t window_size;

	uint16_t checksum;
	uint16_t urgent_pointer;

	uint32_t options;

	void endian_verify()
	{
		source_port = ntohs(source_port);
		dest_port = ntohs(dest_port);
		seq_number = ntohl(seq_number);
		ack_number = ntohl(ack_number);
		window_size = ntohs(window_size);
		checksum = ntohs(checksum);
		options = ntohl(options);
	}

	std::string to_string() {
		std::stringstream ss;
		ss << "Source Port: " << source_port << "\n";
		ss << "Destination Port: " << dest_port << "\n";
		ss << "Sequence Number: " << seq_number << "\n";
		ss << "Acknowledgment Number: " << ack_number << "\n";
		ss << "Window Size: " << window_size << "\n";
		ss << "Checksum: " << checksum << "\n";
		ss << "Urgent Pointer: " << urgent_pointer << "\n";
		ss << "Options: " << std::hex << options << std::dec << "\n";
		return ss.str();
	}

} __attribute__((packed));;

// template <typename T>
// T extracter(const std::vector<uint8_t>& buffer, size_t offset, bool bigendian = true)
// {
// 	T value{};
// 	std::memcpy(&T, buffer.data(), sizeof(T));
// 	if(bigendian)
// 	{
// 		if constexpr (sizeof(T) == 2)
// 		{
// 			value = ntohs(value);
// 		} else if constexpr (sizeof(T) == 4)
// 		{
// 			value = ntohl(value);
// 		} else if constexpr (sizeof(T) == 8)
// 		{
// 			value = __builtin_bswap64(value);
// 		}
// 	}
// 	return value;
// }

int main(int argc, char** argv)
{
	std::vector<uint8_t> vpacket = {
		0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00,
		0x45, 0x00, 0x00, 0x34, 0x3b, 0x3b, 0x40, 0x00, 0x3f, 0x06, 0x91, 0xad, 0x34, 0x22, 0x30, 0xaa,
		0x0a, 0x0e, 0x00, 0x02, 0x01, 0xbb, 0xd0, 0xb0, 0x15, 0x73, 0x67, 0xed, 0x74, 0x40, 0xa7, 0x32,
		0x80, 0x10, 0x00, 0x3f, 0x5f, 0x91, 0x00, 0x00, 0x01, 0x01, 0x08, 0x0a, 0x9a, 0x7a, 0xb8, 0xd3,
		0x2a, 0xe3, 0xbe, 0xa0
	};

	std::vector<uint8_t> vpacket2 = {
		0x01, 0xbb, 0xd0, 0xb0, 0x15, 0x73, 0x67, 0xed, 0x74, 0x40, 0xa7, 0x32,
		0x80, 0x10, 0x00, 0x3f, 0x5f, 0x91, 0x00, 0x00, 0x01, 0x01, 0x08, 0x0a, 0x9a, 0x7a, 0xb8, 0xd3,
		0x2a, 0xe3, 0xbe, 0xa0
	};

	if(vpacket2.size() < 20)
	{
		std::cout << "TCP packet size cant be less then 20 byte. Incomplite header." << std::endl;
	}

	if(vpacket2.size() < sizeof(tcp_packet_header))
	{
		std::cout << "Data size (" << vpacket.size() << ") less than TCP header size" << std::endl;
	}

	size_t headerSize = sizeof(tcp_packet_header);
	tcp_packet_header packet;
	//uint16_t source{};
	//std::memcpy(&source, vpacket2.data(), sizeof(uint16_t));
	std::memcpy(&packet, vpacket2.data(), headerSize);
	// std::cout << "source = " << ntohs(source) << std::endl;
	// std::cout << "headersize = " << headerSize << std::endl;
	// std::cout << "packet = " << packet.to_string();
	// Вывод шестнадцатеричного представления
	packet.endian_verify();
	std::cout << packet.to_string() << std::endl;
	std::cout << uint8_to_hex_string(vpacket2.data(), vpacket2.size()) << std::endl;

}