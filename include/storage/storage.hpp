#pragma once

#include <map>
#include <SFML/Graphics.hpp>

namespace res {

	template<typename T>
	class Storage {
	private:

		std::map<std::string, T> items;

	public:

		Storage() {}
		Storage(const Storage& other)
		 : items(other.items) {}

		~Storage() {}


		//enter the arguments to the constructor after the key (if none, leave only the key)
		template<typename ... Args>
		inline void add(const std::string& key, const Args&...);

		inline void remove(const std::string& key);

		inline void clear();

		inline int size();

		// returns the last item if the key does not match to anything
		T get(const std::string& n);

		// will create a new item if the key does not match to anything
		T operator[](const std::string& n);

	};
	
	class TextureManager {
	private:

		std::map<std::string, sf::Texture*> items;
		
	public:

		Storage() {}
		Storage(const Storage& other)
		 : items(other.items), names(other.names) {}

		~Storage() {}


		//enter the arguments to the constructor after the key (if none, leave only the key)
		template<typename ... Args>
		inline void add(const std::string& key, const Args&...);

		inline void remove(const std::string& key);

		inline void clear();

		inline int size();

		// returns the last item if the key does not match to anything
		T get(const std::string& n);

		// will create a new item if the key does not match to anything
		T operator[](const std::string& n);

	};

}; //namespace res

#include "storage.inl"
