#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <vector>

namespace fd
{
	class Application
	{
	private:
		static std::vector<std::string> arguments;

	public:
		static void Init(int args, char** argv) noexcept;

		static std::vector<std::string> getArguments() noexcept;

		static const std::string getAppDir() noexcept;

		static const std::string getAppPath() noexcept;

		static std::string getResourceDir() noexcept;

		static std::string getResourcePath(const std::string & filename) noexcept;
	};
}

#endif // !APPLICATION_HPP