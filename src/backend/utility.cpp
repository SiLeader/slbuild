
#include<string>

#include<utility.hpp>

void slbuild::utility::replace(std::string& str, const std::string& from, const std::string& to)
{
	std::string::size_type pos=0;
	
	while(pos=str.find(from, pos), pos!=std::string::npos){
		str.replace(pos, from.length(), to);
		pos+=to.length();
	}
}

void slbuild::utility::split(const std::string &str, const std::string &delim, std::vector<std::string>& res)
{
	size_t current=0, found, delimlen=delim.size();

	while((found=str.find(delim, current))!=std::string::npos){
		res.push_back(std::string(str, current, found-current));
		current=found+delimlen;
	}

	res.push_back(std::string(str, current, str.size()-current));
}


