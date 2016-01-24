#pragma once

#include<boost/filesystem.hpp>

const std::string& inc_and_lib(const slbuild::config::build_conf* bc=nullptr);
void Compile(bool isRebuild, const slbuild::config::build_conf& bc, boost::filesystem::path p, std::time_t bin_time);
void Clean(void);
