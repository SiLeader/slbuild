/*
	SiLeader SLBuild
	(C) 2016 SiLeader and VOSystems.
*/

#include<fstream>

#include<boost/filesystem.hpp>

#include"loader.hpp"
#include"utility.hpp"

namespace fs=boost::filesystem;

/*
	author : SiLeader
	create : 2016/01/24
	update : 2016/01/24
	
	return : void
	args
	    conf -> settings load to it.
	    setup_file(default=make.slb) -> setup file's path
*/
void slbuild::config::LoadSettings(slbuild::config::build_conf& conf, const std::string& setup_file)
{
	std::cout<<"Loading Setup File..."<<std::flush;
	
	std::ifstream fin(setup_file);
	std::string str;
	std::array<std::string, 2> arr;
	
	while(!fin.eof()){
		std::getline(fin, str);
		
		slbuild::utility::first_split(str,"=", arr);
		slbuild::utility::remove_spaces(arr[0]);
		std::transform(arr[0].begin(), arr[0].end(), arr[0].begin(), ::tolower);
		
		if(arr[0]=="inc"){
			conf.inc_dirs.push_back(arr[1]);
		
		}else if(arr[0]=="lib_dir"){
			conf.lib_dirs.push_back(arr[1]);
			
		}else if(arr[0]=="lib"){
			conf.lib.push_back(arr[1]);
			
		}else if(arr[0]=="src"){
			conf.src_dirs.push_back(arr[1]);
			
		}else if(arr[0]=="linker"){
			conf.linker=arr[1];
			
		}else{
			conf.compilers.insert(make_pair(arr[0], arr[1]));
			
		}
		
	}
	std::cout<<"[ OK ]"<<std::endl;

}

void slbuild::config::LoadDependency(const slbuild::config::build_conf& conf)
{
	/*
	fs::create_directory("slbuild-cache");
	ofstream fout("slbuild-cache/depend.sls");
	ifstream fin;*/
	
}

