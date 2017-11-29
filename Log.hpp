//Log
#include <fstream>

namespace Engine {

enum formats{
	error,
	normal,
	heading,
	subheading
};

class Log{
public:
	Log(const char * name);
	Log();
	~Log();

	void create_logfile(const char * name);
	void write(const char * entry);
	void write(const char * entry, int format);

private:
	std::fstream file;

};

}//namespace Engine
