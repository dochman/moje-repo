#pragma once
#include <map>
#include <typeinfo>
class MemHelper
{
public:
	struct Info
	{
		size_t size;
		const std::type_info& info;
	};
private:
	static auto& GetMap()
	{
		static std::map<void*, Info> allocs;
		return allocs;
	}
public:
	static MemHelper& G()
	{
		static MemHelper m;
		return m;
	}
	template<typename T>
	T* operator*(T* ptr)
	{
		Info i{ sizeof(T), typeid(T) };
		GetMap().insert(std::make_pair(ptr, i));
		return ptr;
	}
	template<typename T>
	void operator+=(T* ptr)
	{
		GetMap().erase(ptr);
		delete ptr;
	}
	static int GetAllocCount()
	{
		return GetMap().size();
	}

	static int GetAllocCountForType(const type_info& info)
	{
		int res = 0;
		for (auto& e : GetMap())
		{
			if (e.second.info == info)
				++res;
		}
		return res;
	}
};


#define new MemHelper::G() * new 
#define delete MemHelper::G() += 