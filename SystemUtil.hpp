/*********************\
| System utilities.   |
|					  |
| @author David Saxon |
\*********************/

#ifndef UTILITIES_SYSTEMUTIL_H_
#	define UTILITIES_SYSTEMUTIL_H_

namespace util { namespace sys {

//FUNCTIONS
/*!@return the number of processors the machine has*/
inline unsigned getNumProc() {

	//if on windows
#if defined(_WIN32)

	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo);

	return sysinfo.dwNumberOfProcessors;

	//if on linux
#else

	return sysconf(_SC_NPROCESSORS_ONLN);
#endif
}

} } //util //sys

#endif