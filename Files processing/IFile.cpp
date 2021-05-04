#include "IFile.h"

//constructor from base class, derivate class use this
IFile::IFile(const std::string filePath, const std::string mode) : filePath(filePath), length(0)
{
	openMode = std::fstream::binary;
	if (mode.find("r") != std::string::npos) openMode |= std::fstream::in;
	if (mode.find("w") != std::string::npos) openMode |= std::fstream::out;
	if (mode.find("a") != std::string::npos) openMode |= std::fstream::app;
	if (mode.find("t") != std::string::npos) openMode |= std::fstream::trunc;
	if (mode.find("e") != std::string::npos) openMode |= std::fstream::ate;
	if (mode.find("b") != std::string::npos) openMode |= std::fstream::binary;

	file.open(filePath, openMode);
	if (file.is_open())
	{
		file.seekg(0, std::fstream::end);
		length = file.tellg();
		file.seekg(0, std::fstream::beg);
	}
}

IFile::~IFile()
{
	file.close();
}

