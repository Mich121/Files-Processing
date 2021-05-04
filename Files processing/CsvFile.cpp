#include "CsvFile.h"
#include <string>	//getline
#include <sstream> //stringstream
#include<iostream>
#include <limits>

//open in appriopriate mode and count length of file
CsvFile::CsvFile(const std::string filePath, const std::string mode): IFile(filePath, mode)
{
}

//close file
CsvFile::~CsvFile()
{
	file.close();
}

//divide string from separators
std::vector<std::string> CsvFile::Split(std::string str, char delim) 
{
	std::vector<std::string> result;
	std::stringstream ss(str);
	std::string item;
	while (std::getline(ss, item, delim)) 
	{
		result.push_back(item);
	}
	return result;
}

//save vector of points to file and return appropriate file error
IFile::FileError CsvFile::Write(const std::vector<Point>& v)
{
	std::cout << "CSV FILE!!!" << "\n";
	FileError retVal = FileError(ACCESS_DENIED);

	if (!file.is_open())
	{
		retVal = FileError(FILE_INVALID);
	}
	else if (openMode & std::fstream::out)
	{
		int vsize = v.size();
		for (int n = 0; n < vsize; n++)
		{
			file << v[n].x << " " << v[n].y << " " << v[n].z << "\n";
		}
		retVal = FileError(SUCCESS);
	}

	return retVal;
}

//enter to vector points from file and return appropriate file error
IFile::FileError CsvFile::Read(std::vector<Point>& v)
{
	std::cout << "CSV FILE!!!" << "\n";
	FileError retVal = FileError(ACCESS_DENIED);
	if (!file.is_open())
	{
		retVal = FileError(FILE_INVALID);
	}
	else
	{
		Point point;
		char ch;
		std::string text;
		v.clear();
		while (std::getline(file, text))
		{
			while (file >> point.x >> ch >> point.y >> ch >> point.z) 
			{
				v.push_back(point);
			}
		}
		retVal = FileError(SUCCESS);
	}
	return retVal;
}

//enter to struct 'Point' point from file with appropriate index and return appropriate file error
IFile::FileError CsvFile::Read(Point& p, const unsigned long idx)
{
	std::cout << "CSV FILE!!!" << "\n";
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
		std::string text;
		char ch;
		file.seekg(std::ios::beg);
		for (unsigned int i = 0; i < idx - 1; ++i)
			file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::getline(file, text);
		file >> p.x >> ch >> p.y >> ch >> p.z;

		retVal = FileError(SUCCESS);
	}

	return retVal;
}

