/*
 * mystring.hpp
 *
 *  Created on: Sep 2, 2015
 *      Author: cesar
 */

#ifndef MYSTRING_HPP_
#define MYSTRING_HPP_

#include <vector>
#include <string>
using std::string;

struct mystring {
protected:
	char * alloc;
	char * begin;
	char * end;
public:
	mystring(const char * str, int size)
	{
		this->alloc = new char[size];
		this->begin = this->alloc;
		this->end = this->alloc;
		for(; *str != 0 && this->end - this->alloc < size-1;
				++str, ++this->end) {
			*this->end = *str;
		}
		*this->end = 0;
	}
	virtual ~mystring()
	{
		delete this->alloc;
	}
	void ltrim(char ch = ' ')
	{
		while(*this->begin == ch) ++this->begin;
	}
	void rtrim(char ch = ' ')
	{
		while(*(this->end -1) == ch
				&& this->begin < this->end) --this->end;
		*this->end = 0;
	}
	void trim(char ch = ' ')
	{
		this->ltrim(ch);
		this->rtrim(ch);
	}
	int size()
	{
		return this->end - this->begin;
	}
	/**
	 * Perigo: este objeto ser deletado com os retornos desta função ainda em uso.
	 * Se necessário o uso dos retornos posteriormente, copiar seu conteúdo para uma nova variável.
	 */
	const char * pop_front(char delim = ' ')
	{
		this->ltrim(delim);
		char *pop = this->begin;
		for(; *this->begin != 0 && this->begin < this->end;
				++this->begin) {
			if(*this->begin == delim) {
				*this->begin = 0;
				++this->begin;
				break;
			}
		}
		return pop;
	}
	std::vector<const char *> explode(char delim = ' ')
	{
		std::vector<const char *> result;
		this->rtrim(delim);
		while(this->size() > 0)
			result.push_back(this->pop_front(delim));
		return result;
	}
	static std::vector<std::string> explode(
			const char *str,
			char delim = ' ')
	{
		std::vector<std::string> result;
		for(const char *end, *begin = str;
				*begin != 0;
				begin = end) {
			while(*begin == delim) ++begin;
			if(*begin == 0) break;
			end = begin+1;
			while(*end != delim && *end != 0) ++end;
			std::string push(begin, end-begin);
			result.push_back(push);
		}
		return result;
	}
};

#endif /* MYSTRING_HPP_ */
