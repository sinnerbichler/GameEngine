//Log.cpp
#include "Log.hpp"
#include <string>

namespace Engine{
using namespace std;

Log::Log(){}

Log::Log(const char * name)
{
	create_logfile(name);
}

Log::~Log()
{
	file << "</body>" << endl;
	file.close();
}

void Log::create_logfile(const char * name)
{
	if (file.is_open())
	{
		write("Logfile already exists!", error);
		exit;
	}
	file.open(name,  ios::out);

	file << "<!DOCTYPE hmtl>\n" \
	<< "<head>\n<meta charset=\"UTF-8\" />\n<link rel=\"stylesheet\" href=\"stylesheet.css\" />\n" \
	<< "</head>\n<body>" << endl;
}

void Log::write(const char * entry)
{
	write(entry, normal);
}

void Log::write(const char * entry, int format)
{
	if ((format < error) | (format > subheading))
		write("Log.cpp 31: wrong format", Engine::error);
	std::string id;
	switch (format) {
		case (error):
			id = "error"; break;
		case (normal):
			id = "normal";break;
		case (heading):
			id = "heading";break;
		case (subheading):
			id = "subheading";break;
	}

	file << "<p class=\"" << id << "\">" << entry << "</p>" << endl;
}

}//namespace Engine
