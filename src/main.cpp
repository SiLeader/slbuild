/*

*/

#include"loader.hpp"
#include"utility.hpp"

#include<boost/thread.hpp>
#include<boost/filesystem.hpp>
#include<boost/foreach.hpp>

#include<iostream>
#include<map>
#include<thread>
#include<cstdlib>

#define foreach BOOST_FOREACH

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

/*void Compile(bool isRebuild,
	slbuild::config::build_conf& bc,
	fs::recursive_directory_iterator start,
	fs::recursive_directory_iterator end,
	std::time_t bin_time)
{
	std::time_t src_time;
	std::string filename, ext;
	
	for(; start!=end; ++start){
		filename=start->path().filename().string();
		ext=start->path().extension().string();
		slbuild::utility::replace(ext, ".", "");
		
		std::system((bc.compilers[ext]+" "+filename).c_str());
	}
}*/

void Compile(bool isRebuild, const slbuild::config::build_conf& bc, fs::path p, std::time_t bin_time)
{
	
}

void Build(bool isRebuild, slbuild::config::build_conf& bc, const int proc_count)
{
	std::vector<std::thread> th;
	
	fs::path bin("bin/"+bc.bin_name);
	auto bin_time=fs::last_write_time(bin);
	
	fs::recursive_directory_iterator last;
	std::size_t file_count=0;
	/*
	for(fs::recursive_directory_iterator itr("."); itr != last; ++itr){
		if(!fs::is_directory(itr->path()))++file_count;
	}*/
	foreach(const fs::path& p, std::make_pair(fs::recursive_directory_iterator(fs::path(fs::current_path())), fs::recursive_directory_iterator())){
		if(!fs::is_directory(p)) ++file_count;
	}
	
	//if(proc_count!=1){//Not Single Thread Processor
		std::size_t file_per_thread=file_count/proc_count;
		
#		pragma omp parallel for schedule(guided)
		foreach(const fs::path& p, std::make_pair(fs::recursive_directory_iterator(fs::path(fs::current_path())), fs::recursive_directory_iterator())){
			if(!fs::is_directory(p)){
				Compile(isRebuild, bc, p, bin_time);
			}
		}
		/*
		auto fitr=fs::recursive_directory_iterator(fs::current_path());
		for(int c=0; c<proc_count; c++){
			th.push_back(std::thread(Compile, isRebuild,
				bc,
				fitr+(file_per_thread*c),
				fitr+(file_per_thread*(c+1)<file_count ? file_per_thread*(c+1) : file_count),
				bin_time));
		}*/
	/*
	}else{
		Compile(isRebuild,
			bc,
			fs::recursive_directory_iterator(fs::current_path()),
			fs::recursive_directory_iterator(fs::current_path())+file_count,
			bin_time);
	}*/
	
	for(auto&& t : th){
		t.join();
	}
}

void Clean(void)
{
	
}

int main(void)
{
	std::cout<<"SiLeader slbuild (Build : "<<__TIME__<<" )"<<std::endl;
	
	slbuild::config::build_conf bc;
	slbuild::config::FileManage fm(bc);
	
	ShowSettingOverview(bc);
	
	auto proc_count=boost::thread::hardware_concurrency();
	std::cout<<"\nCount of Logical Processors : "<<proc_count<<std::endl;
	
	std::string command;
	
	do{
		std::cout<<">>>"<<std::flush;
		std::cin>>command;
		
		if(command=="help"){
			
		}else if(command=="build"){
			Build(false, bc, proc_count);
			
		}else if(command=="rebuild"){
			Build(true, bc, proc_count);
			
		}else if(command=="clean"){
			Clean();
			
		}else{
			std::cerr<<"Error : Unknown command"<<std::endl;
			
		}
		
		std::cout<<std::endl;
	}while(command!="exit");
}
