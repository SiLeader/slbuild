/*
	SiLeader SLBuild
	(C) 2016 SiLeader and VOSystems.
*/

#include<fstream>

#include"loader.hpp"
#include"utility.hpp"

namespace fs=boost::filesystem;

using namespace slbuild::config;

FileManage::FileManage(slbuild::config::build_conf& bc)
	: _bc(bc)
{
	LoadSettings(_bc);
}


void FileManage::LoadSettings(slbuild::config::build_conf& conf, const std::string& setup_file)
{
	std::ifstream fin(setup_file);
	std::string str;
	std::vector<std::string> arr;
	
	while(!fin.eof()){
		std::getline(fin, str);
		slbuild::utility::remove_spaces(str);
		
		slbuild::utility::split(str,"=", arr);
		
		if(arr[0]=="inc"){
			conf.inc_dirs.push_back(arr[1]);
		
		}else if(arr[0]=="lib"){
			conf.lib_dirs.push_back(arr[1]);
			
		}else if(arr[0]=="src"){
			conf.src_dirs.push_back(arr[1]);
			
		}else if(arr[0]=="linker"){
			conf.linker=arr[1];
			
		}else{
			conf.compilers.insert(make_pair(arr[0], arr[1]));
			
		}
		
		arr.clear();
	}
}
