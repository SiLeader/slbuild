/*

*/

#pragma once

#include<string>
#include<vector>

namespace slbuild
{
	namespace utility
	{
		void replace (std::string& str, const std::string& from, const std::string& to);
		void split(const std::string &str, const std::string &delim, std::vector<std::string>& res);
		void first_split(const std::string &str, const std::string &delim, std::array<std::string, 2>& res);
		
		inline void remove_spaces(std::string& str)
		{
			slbuild::utility::replace(str, " ", "");
			slbuild::utility::replace(str, "\t", "");
			slbuild::utility::replace(str, "\n", "");
			slbuild::utility::replace(str, "\r", "");
		}
		
		inline bool IsFileExist(const std::string& filename)
		{
			FILE  *fp;
			if((fp = fopen(filename.c_str(), "r")) == nullptr)	return false;
			fclose(fp);
			return true;
		}
	}
}
