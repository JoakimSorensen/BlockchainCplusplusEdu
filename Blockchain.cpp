#include "Blockchain.h"

Blockchain::Blockchain() {
	_vChain.emplace_back(Block(0, "Genesis Block"));
	_nDifficulty = 6;
}

void Blockchain::addBlock(Block bNew) {
	bNew.sPrevHash = _GetLastBlock().getHash();
	bNew.mineBlock(_nDifficulty);
	_vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const {
	return _vChain.back();
}
