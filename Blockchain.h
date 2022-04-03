#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H
#include <cstdint>
#include <vector>
#include "Block.h"

class Blockchain {
public:
	Blockchain();

	void addBlock(Block bNew);

private:
	uint32_t _nDifficulty;
	std::vector<Block> _vChain;

	Block _GetLastBlock() const;
};


#endif
