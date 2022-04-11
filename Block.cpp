#include "Block.h"
#include "sha256.h"


Block::Block(uint32_t nIndexIn, const std::string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
	_nNonce = -1;
	_tTime = time(nullptr);
}


std::string Block::getHash() {
	return _sHash;
}


void Block::mineBlock(uint32_t nDifficulty) {
	char cstr[nDifficulty + 1];
	for (uint32_t i = 0; i < nDifficulty; i++) {
		cstr[i] = '0';
	}
	cstr[nDifficulty] = '\0';

	std::string str(cstr);

	do {
		_nNonce++;
		_sHash = _calculateHash();
	} while (_sHash.substr(0, nDifficulty) != str);

	std::cout << "Block mined: " << _sHash << std::endl;

}

//compiler might ignore this inline
inline std::string Block::_calculateHash() const {
	std::stringstream ss;
	ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

	return sha256(ss.str());
}


bool Block::checkBlockIntegrity() {
	// implies all other values are also the same, i.e.
	// _nIndex, _tTime, _sData, _nNonce, sPrevHash
	return _sHash == _calculateHash();
}


