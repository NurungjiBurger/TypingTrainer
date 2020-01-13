#pragma once
#include <fstream>

class FileManager : public std::fstream{
public :
	FileManager();
	FileManager(const FileManager& other);
	virtual ~FileManager();
	// 읽기

	// 쓰기

private :

};

