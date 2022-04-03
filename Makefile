
LINK_TARGET = BlockchainMain.exe

OBJS = \
	   BlockchainMain.o \
	   Blockchain.o \
	   Block.o \
	   sha256.o

REBUILDABLES = $(OBJS) $(LINK_TARGET)


all: $(LINK_TARGET)
	echo All Done

$(LINK_TARGET): $(OBJS)
	g++ -std=c++11 -g -Wall -o $@ $^

%.o : %.cpp
	g++ -std=c++11  -g -Wall -o $@ -c $<
BlockchainMain.o : Block.h Blockchain.h
Blockchain.o : Blockchain.h
Block.o : Block.h sha256.h


clean :
	rm -f $(REBUILDABLES)
	echo clean done


run: BlockchainMain.exe 
	./BlockchainMain.exe
