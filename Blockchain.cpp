#include "Blockchain.h"

Blockchain::Blockchain() {
	_vChain.emplace_back(Block(0, "Genesis Block"));
	_nDifficulty = 4;
}

bool Blockchain::addBlock(uint32_t indexIn, std::string data) {
	Block bNew = Block(indexIn, data);
	bNew.sPrevHash = _GetLastBlock().getHash();
	bNew.mineBlock(_nDifficulty);
	_vChain.push_back(bNew);
	return checkChainIntegrity();
}

Block Blockchain::_GetLastBlock() const {
	return _vChain.back();
}

bool Blockchain::checkChainIntegrity() {
	for (uint32_t i = 1; i < _vChain.size(); i++) {
		if (!_vChain[i].checkBlockIntegrity()) {
			return false;
		}
	}
	return true;
}
