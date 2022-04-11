#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H
#include <cstdint>
#include <iostream>
#include <sstream>

class Block {
public:
	std::string sPrevHash;

	Block(uint32_t nIndexIn, const std::string &sDataIn);

	std::string getHash();

	void mineBlock(uint32_t nDifficulty);
	
	bool checkBlockIntegrity();
	
private:
	uint32_t _nIndex;
	int64_t _nNonce;
	std::string _sData;
	std::string _sHash;
	time_t _tTime;

	std::string _calculateHash() const;
		
};

#endif
