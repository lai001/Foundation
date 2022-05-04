#include "File.hpp"
#include <sstream>
#include <fstream>
#include <assert.h>
#include "defer.hpp"

namespace ks
{
	std::string File::read(const std::string & filePath, bool* status)
	{
		std::string content;
		std::ifstream inputFileStream;
		defer { inputFileStream.close(); };
		std::stringstream stringstream;
		inputFileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			inputFileStream.open(filePath);
			stringstream << inputFileStream.rdbuf();
			content = stringstream.str();
			if (status)
			{
				*status = true;
			}
		}
		catch (std::ifstream::failure e)
		{
			if (status)
			{
				*status = false;
			}
		}
		return content;
	}

	bool File::write(const std::string& content, const std::string& filePath)
	{
		std::ofstream file;
		defer{ file.close(); };

		file.exceptions(std::ofstream::badbit);
		bool status;
		try
		{
			file.open(filePath);
			file << content;
			status = true;
		}
		catch (const std::exception&)
		{
			status = false;
		}

		return status;
	}

	std::vector<char> File::readBinData(const std::string & filePath, bool * status)
	{
		std::ifstream file(filePath, std::ios::binary | std::ios::ate);
		std::streamsize size = file.tellg();
		file.seekg(0, std::ios::beg);
		assert(size > 0);
		std::vector<char> buffer(size);
		if (file.read(buffer.data(), size))
		{
			if (status)
			{
				*status = true;
			}
		}
		else
		{
			if (status)
			{
				*status = false;
			}
		}
		return buffer;
	}
}