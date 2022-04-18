#include "Blockchain.h"
#include <climits>

inline const char* boolToString(bool b) {
	return b ? "Chain validated" : "chain invalid";
}

int main() {
	Blockchain bChain = Blockchain();
	bool chainIntegrity = true;
	int numberOfNodes = 1;
	
	uint32_t indexIn = 1;

	std::cout << "Enter number of nodes for the chain: " << std::endl;
	std::cin >> numberOfNodes;
	
	Blockchain bNodes[numberOfNodes];

	// Ignore to the end of line
	std::cin.ignore(INT_MAX, '\n');
	
	std::cout << "Mining genesis block..." << std::endl;
	bChain.addBlock(0, "Genesis");

	while (true) {
		char data[256];

		std::cout << "Enter data for new block: \n('ctrl + c' to stop)" << std::endl;
		std::cin.getline(data, 256);
		
		std::string strData(data);

		std::cout << "Mining block " << indexIn << "..." << std::endl;
		chainIntegrity = bChain.addBlock(indexIn, strData);

		std::cout << boolToString(chainIntegrity) << std::endl;
		
		// distribute validated chain to nodes
		// TODO: implement some conscensus
		int i = 0;
		while (chainIntegrity && i < numberOfNodes) {
			bNodes[i] = bChain;
			i++;
		}
		
		indexIn++;
	}
	std::cout << "Shutting down chain..." << std::endl;

	return 0;
}
