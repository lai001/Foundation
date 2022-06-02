#ifndef Foundation_File_hpp
#define Foundation_File_hpp
#include <string>
#include <vector>
#include "defs.hpp"

namespace ks
{
	class Foundation_API File
	{
	public:
		static std::string read(const std::string& filePath, bool* status);

		static std::vector<char> readBinData(const std::string& filePath, bool* status);

		static bool write(const std::string& content, const std::string& filePath);
	};
}

#endif // !Foundation_File_hpp
