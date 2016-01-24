#include"loader.hpp"
#include"utility.hpp"
#include"commands.hpp"

#include<boost/filesystem.hpp>
#include<omp.h>

#include<vector>

namespace fs=boost::filesystem;

void Build(bool isRebuild, slbuild::config::build_conf& bc, const int proc_count, const std::time_t bin_time)
{
	const fs::recursive_directory_iterator last;
	std::size_t file_count=0;
	
	for(fs::recursive_directory_iterator itr("."); itr != last; ++itr){
		if(fs::is_regular_file(*itr))++file_count;
	}
	
	inc_and_lib(&bc);
	fs::create_directory("obj");
#	pragma omp parallel for schedule(guided)
	for(fs::recursive_directory_iterator itr("."); itr != last; ++itr){
		if(fs::is_regular_file(*itr)){
			Compile(isRebuild, bc, *itr, bin_time);
		}
	}
	
}
