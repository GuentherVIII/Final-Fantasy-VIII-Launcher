/*
Final Fantasy VIII Launcher
Copyright 2007, 2008 Tobias Sebring


This file is part of Final Fantasy VII Launcher.

Final Fantasy VII Launcher is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 3.

Final Fantasy VII Launcher is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Final Fantasy VII Launcher.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _LOG_H
#define _LOG_H

#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <fstream>
#include <map>
//#include <typeinfo>
#include <ddraw.h>
#include <d3d.h>

#define LOG_PUT(fmt, ...) { if(m_count++ != 0) m_at += _snprintf_s(m_logbuffer+m_at, m_logbufferSize-m_at, m_logbufferSize-m_at, ", "); m_at += _snprintf_s(m_logbuffer+m_at, m_logbufferSize-m_at, m_logbufferSize-m_at, fmt, __VA_ARGS__); return *this; }
#define LOGBUFFERSIZE_DEFAULT 10000
enum LOGLEVEL { LL_DISABLED = 0, LL_LIMITED = 1, LL_FULL = 2 };


/**************************************************
* NAME: cLog                                      *
* DESC: Base logging class                        *
**************************************************/
class cLog {
public:
	cLog(unsigned int _logbufferSize = LOGBUFFERSIZE_DEFAULT) : m_logbufferSize(_logbufferSize), m_at(0), m_count(0) {
		//allocate logbuffer
		m_logbuffer = new char[m_logbufferSize];
	}

	~cLog() {
		//cleanup
		delete[] m_logbuffer;
		m_logbuffer = NULL;
	}

	static void SetLogLevel(LOGLEVEL _ll);
	static void GetLogLevel(LOGLEVEL *_ll);

	cLog& cls(void) { if(m_logbuffer != NULL) m_logbuffer[0] = '\0'; m_at = m_count = 0; return *this; }
	cLog& w(const char *fmt, ...) { va_list args; va_start(args, fmt); m_at += _vsnprintf_s(m_logbuffer+m_at, m_logbufferSize-m_at, m_logbufferSize-m_at, fmt, args); return *this; }
	cLog& p(int a) { LOG_PUT("int = %d"); }
	cLog& p(void *a) { LOG_PUT("void * = %#010lx", a); }
	cLog& p(DWORD a) { LOG_PUT("DWORD = %#010lx (%d)", a, a); }
	cLog& p(REFIID a);
	cLog& p(LPVOID FAR *a) { LOG_PUT("LPVOID FAR * = %#010lx", a); }
	cLog& p(HRESULT a);
	virtual cLog& flush(LOGLEVEL _ll) = 0;

	virtual int Log(LOGLEVEL _ll, char *_fmt, ...) = 0;

protected:
	unsigned int m_at, m_count;
	char *m_logbuffer;
	const unsigned int m_logbufferSize;
	
	static LOGLEVEL m_logLevel;
	static std::map<HRESULT, char *> m_errcodes;
};


/**************************************************
* NAME: cFileLog                                  *
* DESC: File output logging subclass              *
**************************************************/
class cFileLog : public cLog {
public:
	cFileLog(char *_filename, unsigned int _logbufferSize = LOGBUFFERSIZE_DEFAULT) : cLog(_logbufferSize) {
		//save filename
		int s = strlen(_filename);
		m_filename = new char[s+1];
		strcpy_s(m_filename, s+1, _filename);

		//open output filestream
		m_ofs.open(m_filename, std::ios::out);
		if(!m_ofs.is_open()) {
			//error opening file
		}
	}

	~cFileLog() {
		//cleanup
		delete[] m_filename;
		m_filename = NULL;

		if(m_ofs.is_open()) m_ofs.close();
	}

	cLog& flush(LOGLEVEL _ll) {
		if(!m_ofs.is_open() || m_logbuffer == NULL || (_ll > cLog::m_logLevel || cLog::m_logLevel == LL_DISABLED)) {
		} else m_ofs << m_logbuffer;
		cls();

		return *this;
	}

	int Log(LOGLEVEL _ll, char *_fmt, ...) {
		if(!m_ofs.is_open()) return 0;
		if(m_logbuffer == NULL) return 0;
		if(_ll > cLog::m_logLevel || cLog::m_logLevel == LL_DISABLED) return 2;

		va_list argptr;
		va_start(argptr, _fmt);

		_vsnprintf_s(m_logbuffer, m_logbufferSize, m_logbufferSize, _fmt, argptr);

		//output logbuffer to filestream
		m_ofs << m_logbuffer;
		cls();

		return 1;
	}

protected:
	char *m_filename;
	std::ofstream m_ofs;
};

#endif