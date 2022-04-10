#include "File.hpp"
#include <sstream>
#include <fstream>

namespace fd
{
	std::string readFile(const std::string & FilePath)
	{
		std::string SourceShader;
		std::ifstream InputFileStream;
		std::stringstream ShaderStream;
		InputFileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			InputFileStream.open(FilePath);
			ShaderStream << InputFileStream.rdbuf();
			SourceShader = ShaderStream.str();
			InputFileStream.close();
		}
		catch (std::ifstream::failure e)
		{
			throw e;
		}
		return SourceShader;
	}
}