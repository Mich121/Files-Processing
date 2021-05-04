#pragma once
#include <fstream>
#include <vector>
#include <iostream>
#include "Point.h"
#include "FileError.h"
#include "IFile.h"

class BinaryFile: public IFile
{
public:
	BinaryFile(const std::string, const std::string);
	~BinaryFile();

	IFile::FileError Write(const std::vector<Point>&);
	IFile::FileError Read(std::vector<Point>&);
	IFile::FileError Read(Point&, const unsigned long);
};


