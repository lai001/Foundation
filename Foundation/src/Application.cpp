#include "Application.hpp"
#include <assert.h>
#include "File.hpp"
#include "defer.hpp"

namespace ks
{
	std::vector<std::string> Application::arguments;

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
		return File::getParentDir(getAppPath());
	}

	const std::string Application::getAppPath() noexcept
	{
		assert(arguments.empty() == false);
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