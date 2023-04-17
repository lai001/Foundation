#include "File.hpp"
#include <sstream>
#include <fstream>
#include <filesystem>
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

	bool ks::File::isReadable(const std::string & filePath)
	{
		const std::ifstream stream(filePath.c_str());
		return stream.good();
	}

	std::string ks::File::getParentDir(const std::string& path)
	{
		const std::filesystem::path p = std::filesystem::path(path);
		const std::filesystem::path parent = p.parent_path();
		return parent.string();
	}

	std::string ks::File::pathJoin(const std::vector<std::string>& pathComponents)
	{
		std::filesystem::path path = "";
		for (const std::string& pathComponent : pathComponents)
		{
			path = path / pathComponent;
		}
		return path.string();
	}

	bool ks::File::createDirectory(const std::string& path)
	{
		const std::filesystem::path dir(path);
		return std::filesystem::create_directory(dir);
	}
}