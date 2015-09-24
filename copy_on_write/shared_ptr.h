/*
   	智能指针，辅助隐式共享的实现
 */

#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <iostream>
#include <stddef.h>

namespace MS
{
	// 共享指针类
	template <class T>
	struct U_Ptr
	{
		T *ptr;     // 所存储的指针
		size_t cnt; // 计数器

		U_Ptr(T *p)
			: ptr(p)
			, cnt(1)
		{
		}
		
		virtual ~U_Ptr()
		{
			delete ptr;
			ptr = NULL;
		}

		void operator++()
		{
			++cnt;
		}

		void operator--()
		{
			--cnt;
		}

		size_t GetShareds() const
		{
			return cnt;
		}

		T * operator->()
		{
			return ptr;
		}

		T & operator*()
		{
			return *ptr;
		}
	};

	// 针对指针类型作特化
	template <class T>
	struct U_Ptr<T *>
	{
		typedef T * pointer;
		pointer *ptr;     // 所存储的指针
		size_t cnt; // 计数器

		U_Ptr(pointer *p)
			: ptr(p)
			, cnt(1)
		{
		}
		
		virtual ~U_Ptr()
		{
			if(*ptr != NULL)
				delete []*ptr;  // 自动回收内存
			delete ptr;
			ptr = NULL;
		}

		void operator++()
		{
			++cnt;
		}

		void operator--()
		{
			--cnt;
		}

		size_t GetShareds() const
		{
			return cnt;
		}

		pointer* operator->()
		{
			return ptr;
		}

		pointer & operator*()
		{
			return *ptr;
		}
	};

	template <class T>
	class Share_Ptr
	{
	public:
		Share_Ptr(T val = T())
			: ptr(new U_Ptr<T>(new T(val)))
		{
		}

		Share_Ptr(const Share_Ptr<T> &s_ptr)
			: ptr(s_ptr.ptr)
		{
			++(*ptr);
		}

		Share_Ptr<T> & operator=(const Share_Ptr<T> &s_ptr)
		{
			ClearPtr();
			new (this) Share_Ptr<T>(s_ptr); // 调用拷贝构造
			return *this;
		}

		virtual ~Share_Ptr()
		{
			ClearPtr();
		}

		T & operator*() const
		{
			return **ptr;
		}

		// 标识当前仅剩一个了
		bool isSignal() const
		{
			if(ptr -> GetShareds() == 1)
				return true;
			return false;
		}

	protected:
		void ClearPtr()
		{
			--(*ptr);
			if(ptr -> GetShareds() == 0)
			{

				delete ptr;
				ptr = NULL;
			}
		}

	protected:
		U_Ptr<T> *ptr;

	};
};
#endif

