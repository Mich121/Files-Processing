#pragma once
#include <fstream>
#include <vector>
#include <iostream>
#include "Point.h"
#include "FileError.h"
#include "IFile.h"

class CsvFile: public IFile
{
public:
	CsvFile(const std::string, const std::string);
	~CsvFile();
	std::vector<std::string> Split(std::string str, char delim);

	IFile::FileError Write(const std::vector<Point>&);
	IFile::FileError Read(std::vector<Point>&);
	IFile::FileError Read(Point&, const unsigned long);
};

