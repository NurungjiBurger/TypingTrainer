#pragma once
#include <fstream>

class FileManager : public std::fstream{
public :
	FileManager();
	FileManager(const FileManager& other);
	virtual ~FileManager();
	// �б�

	// ����

private :

};

