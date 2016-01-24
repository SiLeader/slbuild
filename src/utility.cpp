
#include<string>
#include<array>

#include"utility.hpp"

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

void slbuild::utility::first_split(const std::string &str, const std::string &delim, std::array<std::string, 2>& res)
{
	size_t current=0, found=str.find(delim, current), delimlen=delim.size();
	
	/*
	while((found=str.find(delim, current))!=std::string::npos){
		res.push_back(std::string(str, current, found-current));
		current=found+delimlen;
	}
	*/
	if(found!=std::string::npos){
		res[0]=std::string(str, current, found);
		current=found+delimlen;
		res[1]=std::string(str, current, str.size()-current);
	}
}
