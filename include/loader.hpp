/*
	SiLeader SLBuild
	(C) 2016 SiLeader and VOSystems.
*/

#pragma once

namespace slbuild
{
	struct Config
	{
		std::map<std::string, std::string> compilers;//<compiler's name, suffix>
		std::string linker;
		std::vector<std::string> inc_dirs;
		std::vector<std::string> lib_dirs;
		std::vector<std::string> src_dirs;
		
		std::string compiler_args;
		std::string linker_args;
	};
	
	namespace core
	{
		class loader
		{
		private:
			
			
		public:
			
		}
	}
}
