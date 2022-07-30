#include <iostream>
#include <fstream>

using namespace std;

struct e_ident
{
	int magic;
	char bits; // 1 for 32. 2 for 64
	char endian; // 1 for little. 2 for big
	char version;
	char os;
	char pad[8];
	short int objectType;
	short architecture;
	int originalElfVersion;
	void * entryPoint; // Compile this in 64 bit when viewing 64 bit elf files.
	void * programHeaderTable;
	void * sectionHeaderTable;
	int architectureDependentData;
	short headerSize;
	short programHeaderSize;
	short programHeaderEntries;
	short sectionHeaderSize;
	short sectionHeaderEntries;
	short indexOfSectionWithSectionNames;
};

int main()
{
	ifstream f("empty");
	e_ident elfHeader;
	cout << "Elf header size is" << sizeof(elfHeader) << endl;
	f.read((char*)(&elfHeader), sizeof(elfHeader) );
	cout << (int)elfHeader.magic << " " << endl;
	cout << (int)elfHeader.bits << endl;
	cout << (int)elfHeader.endian << endl;
	cout << (int)elfHeader.version << endl;
	cout << (int)elfHeader.os << endl;
	cout << (int)elfHeader.pad[0] << endl;
	cout << (int)elfHeader.objectType << endl;
	cout << (int)elfHeader.architecture << endl;
	cout << (int)elfHeader.originalElfVersion << endl;
	cout << elfHeader.entryPoint << endl;
	cout << elfHeader.programHeaderTable << endl;
	cout << elfHeader.sectionHeaderTable << endl;
	cout << (int)elfHeader.architectureDependentData << endl;
	cout << (int)elfHeader.headerSize << endl;
	cout << (int)elfHeader.programHeaderSize << endl;
	cout << (int)elfHeader.programHeaderEntries << endl;
	cout << (int)elfHeader.sectionHeaderSize << endl;
	cout << (int)elfHeader.sectionHeaderEntries << endl;
	cout << (int)elfHeader.indexOfSectionWithSectionNames << endl;
	return 0;
}

