/*

*/

#include"loader.hpp"
#include"utility.hpp"
#include"commands.hpp"
#include"build.hpp"

#include<boost/filesystem.hpp>
#include<boost/foreach.hpp>

#include<iostream>
#include<map>
#include<thread>
#include<cstdlib>


namespace fs=boost::filesystem;

inline void ShowSettingOverview(slbuild::config::build_conf& bc)
{
	std::cout<<"[Suffix]"<<std::endl;
	for(auto&& m : bc.compilers){
		std::cout<<"    "<<m.first<<" -> "<<m.second<<std::endl;
	}
	
	std::cout<<"\n[Linker]"<<std::endl
		<<"    "<<bc.linker<<std::endl;
	
	std::cout<<"\n[Include Directories]"<<std::endl;
	for(auto&& inc : bc.inc_dirs){
		std::cout<<"    "<<inc<<std::endl;
	}
	
	std::cout<<"\n[Library Directories]"<<std::endl;
	for(auto&& lib : bc.lib_dirs){
		std::cout<<"    "<<lib<<std::endl;
	}
	
	std::cout<<"\n[Source Directories]"<<std::endl;
	for(auto&& src : bc.src_dirs){
		std::cout<<"    "<<src<<std::endl;
	}
}

inline void ShowHelp(void)
{
	std::cout<<"[Help]"<<std::endl
		<<"    build   : build changed source file."<<std::endl
		<<"    rebuild : build all source file."<<std::endl
		<<"    clean   : clean object file."<<std::endl
		<<"    help    : show all commands."<<std::endl;
}

int main(void)
{
	std::cout<<"SiLeader slbuild (Build Name:"<<__TIME__<<")\n"<<std::endl;
	
	slbuild::config::build_conf bc;
	slbuild::config::LoadSettings(bc);
	
	std::size_t bin_time=0;
	if(slbuild::utility::IsFileExist("bin/"+bc.bin_name)){
		fs::path bin("bin/"+bc.bin_name);
		bin_time=fs::last_write_time(bin);
	}
	
	ShowSettingOverview(bc);
	
	auto proc_count=std::thread::hardware_concurrency();
	std::cout<<"\nCount of Logical Processors : "<<proc_count<<std::endl;
	
	std::string command;
	
	do{
		std::cout<<">>>"<<std::flush;
		std::cin>>command;
		
		if(command=="help"){
			ShowHelp();
			
		}else if(command=="build"){
			Build(false, bc, proc_count, bin_time);
			
		}else if(command=="rebuild"){
			Build(true, bc, proc_count, bin_time);
			
		}else if(command=="clean"){
			Clean();
			
		}else if(command=="reload"){
			slbuild::config::LoadSettings(bc);
			slbuild::config::LoadDependency(bc);
			
		}else if(command!="exit"){
			std::cerr<<"Error : Unknown command"<<std::endl;
			
		}
		
		std::cout<<std::endl;
	}while(command!="exit");
}
