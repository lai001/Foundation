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

		static bool isReadable(const std::string& filePath);

		static std::string getParentDir(const std::string& path);

		static std::string pathJoin(const std::vector<std::string>& pathComponents);
	};
}

#endif // !Foundation_File_hpp
