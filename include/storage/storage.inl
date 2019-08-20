#include "storage.hpp"

#include <utility>

namespace res {

	template<class T>
	template<typename ... Args>
	inline void Storage<T>::add(const std::string& key, const Args&... args)
	{
		items.emplace(std::make_pair(key, args...));
	}

	template<class T>
	inline void Storage<T>::remove(const std::string& key)
	{
		items.erase(key);
	}

	template<class T>
	inline void Storage<T>::clear()
	{
		items.clear();
	}

	template<class T>
	T Storage<T>::get(const std::string& n) 
	{
		try
		{	
			return items.at(n);
		} 
		catch( const std::exception& e )
		{
			//logError(e.what());
		}
	}

	template<class T>
	int Storage<T>::size() {
		return items.size();
	}

	template<class T>
	T Storage<T>::operator[](const std::string& n)
	{
		return *items.at(n);
	}


}; //namespace res