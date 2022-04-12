#include "Blockchain.h"

inline const char* boolToString(bool b) {
	return b ? "Chain validated" : "chain invalid";
}

int main() {
	Blockchain bChain = Blockchain();
	bool chainIntegrity = true;
	
	uint32_t indexIn = 1;
	while (true) {
		char data[256];

		std::cout << "Enter data for new block: \n('q' to stop)" << std::endl;
		std::cin.getline(data, 256);
		
		if (data[0] == 'q') {
			std::cout << "Shutting down chain..." << std::endl;
			break;
		}

		std::string strData(data);

		std::cout << "Mining block " << indexIn << "..." << std::endl;
		chainIntegrity = bChain.addBlock(indexIn, strData);
		
		std::cout << boolToString(chainIntegrity) << std::endl;
		indexIn++;
	}

	return 0;
}
