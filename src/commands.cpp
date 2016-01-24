#include"loader.hpp"
#include"utility.hpp"
#include"commands.hpp"

#include<boost/filesystem.hpp>

#include<cstdlib>
#include<sstream>

namespace fs=boost::filesystem;

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

const std::string& inc_and_lib(const slbuild::config::build_conf* bc)
{
	static std::string inclib;
	
	if(bc!=nullptr){
		std::stringstream build;
		
		for(auto&& inc : bc->inc_dirs){
			build<<"-I"<<inc<<" ";
		}
		
		for(auto&& lib_dir : bc->lib_dirs){
			build<<"-L"<<lib_dir<<" ";
		}
		
		for(auto&& lib : bc->lib){
			build<<"-l"<<lib<<" ";
		}
	}
	return inclib;
}

void Compile(bool isRebuild, const slbuild::config::build_conf& bc, fs::path p, std::time_t bin_time)
{
	if(!isRebuild){
		auto src_time=fs::last_write_time(p);
		
		if(bin_time>src_time)return;
	}
	std::string ext=p.extension().string();
	slbuild::utility::replace(ext, ".", "");
	
	auto cc_itr=bc.compilers.find(ext);
	if(cc_itr==bc.compilers.end())return;
	
	std::system((bc.compilers.at(ext)+" -o obj/"+p.stem().string()+"_"+ext+".obj "+inc_and_lib()+" -c "+p.filename().string()).c_str());
}



void Clean(void)
{
	
}

