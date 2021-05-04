#include "BinaryFile.h"

//open in appriopriate mode and count length of file
BinaryFile::BinaryFile(const std::string filePath, const std::string mode): IFile::IFile(filePath, mode)
{
}

//close file
BinaryFile::~BinaryFile()
{
	file.close();
}

//save vector of points to file and return appropriate file error
IFile::FileError BinaryFile::Write(const std::vector<Point>& v)
{
	std::cout << "BINARY FILE!!!" << "\n";
	FileError retVal = FileError(ACCESS_DENIED);

	if (!file.is_open())
	{
		retVal = FileError(FILE_INVALID);
	}
	else if (openMode & std::fstream::out)
	{
		file.write((const char*)v.data(), v.size() * sizeof(Point));
		retVal = FileError(SUCCESS);
	}

	return retVal;
}

//enter to vector points from file and return appropriate file error
IFile::FileError BinaryFile::Read(std::vector<Point>& v)
{
	std::cout << "BINARY FILE!!!" << "\n";
	FileError retVal = FileError(ACCESS_DENIED);

	if (!file.is_open())
	{
		retVal = FileError(FILE_INVALID);
	}
	else if (openMode & std::fstream::in)
	{
		v.clear();
		v.resize(length / sizeof(Point));
		file.seekg(0, std::fstream::beg);
		file.read((char*)v.data(), length);
		retVal = FileError(SUCCESS);
	}

	return retVal;
}

//enter to struct 'Point' point from file with appropriate index and return appropriate file error
IFile::FileError BinaryFile::Read(Point& p, const unsigned long idx)
{
	std::cout << "BINARY FILE!!!" << "\n";
	FileError retVal = FileError(ACCESS_DENIED);

	if (!file.is_open())
	{
		retVal = FileError(FILE_INVALID);
	}
	else if (idx * sizeof(Point) > length)
	{
		retVal = FileError(OUT_OF_BOUNDS);
	}
	else if (openMode & std::fstream::in)
	{
		file.seekg(idx * sizeof(Point));
		file.read((char*)(&p), sizeof(Point));
		retVal = FileError(SUCCESS);
	}

	return retVal;
}
