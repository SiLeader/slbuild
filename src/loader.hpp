/*
	SiLeader SLBuild
	(C) 2016 SiLeader and VOSystems.
*/

#pragma once

#include<boost/filesystem.hpp>
#include<map>

namespace slbuild
{
	namespace config
	{
		struct build_conf
		{
			std::map<std::string, std::string> compilers;//<suffix, compiler's name>
			std::string linker;
			std::vector<std::string> inc_dirs;
			std::vector<std::string> lib_dirs;
			std::vector<std::string> src_dirs;
			std::vector<std::string> lib;
			std::string bin_name;
		};
		
		
		void LoadSettings(slbuild::config::build_conf& conf, const std::string& setup_file="make.slb");
		void LoadDependency(const slbuild::config::build_conf& conf);
	}
	
}
