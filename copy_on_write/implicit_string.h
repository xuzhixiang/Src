
#ifndef IMPLICIT_STRING_H
#define IMPLICIT_STRING_H

#include "shared_ptr.h"

namespace MS
{
	class ms_string
	{
		typedef Share_Ptr<char *> VAR;
	public:
		ms_string();
		ms_string(const char *data);
		ms_string(const ms_string &str);

		ms_string & operator=(const ms_string &str);

		~ms_string();

		const char at(size_t index) const;
		// 测试函数
		char & test(size_t index);

		char & operator[](size_t index);
		const char operator[](size_t index) const;

		const char * c_str() const;

		const char * data() const;

		ms_string & append(const char c);
		ms_string & append(const char * val);
		ms_string & append(const ms_string & str);

		size_t size() const;
	private:
		void destroy();

		/*
		 	仅实现以上这些功能，其他功能可自行添加
		 */

	private:
		VAR *m_data;

		size_t m_size;
	};
};

#endif

