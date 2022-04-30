#include "Application.hpp"
#include "defer.hpp"

namespace ks
{
	std::vector<std::string> Application::arguments;

	std::string getFolder(const std::string& Filename) noexcept
	{
		std::string Directory;
		const size_t LastSlashIndex = Filename.rfind('\\');
		if (std::string::npos != LastSlashIndex)
		{
			Directory = Filename.substr(0, LastSlashIndex);
		}
		return Directory;
	}

	void Application::Init(int args, char** argv) noexcept
	{
		arguments.clear();
		for (int i = 0; i < args; ++i)
		{
			arguments.push_back(argv[i]);
		}
	}

	std::vector<std::string> Application::getArguments() noexcept
	{
		return arguments;
	}

	const std::string Application::getAppDir() noexcept
	{
		return getFolder(getAppPath());
	}

	const std::string Application::getAppPath() noexcept
	{
		return arguments[0];
	}

	std::string Application::getResourceDir() noexcept
	{
		std::string AppDir = Application::getAppDir();
		std::string path = AppDir + "/" + "Resource";
		return path;
	}

	std::string Application::getResourcePath(const std::string & filename) noexcept
	{
		std::string dir = getResourceDir();
		std::string path = dir + "/" + filename;
		return path;
	}
}