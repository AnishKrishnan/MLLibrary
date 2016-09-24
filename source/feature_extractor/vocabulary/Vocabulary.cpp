#include "Vocabulary.h"

Vocabulary::Vocabulary() : _vocabulary()
{
	_currentIndexValue = 0;
}

int Vocabulary::Add(const std::string & token)
{
	std::map<std::string, int>::const_iterator it = _vocabulary.find(token);

	if (it != _vocabulary.end())
	{
		return _vocabulary[token];
	}
	
	int newIndex = _currentIndexValue;
	_vocabulary[token] = newIndex;
	_currentIndexValue++;

	return newIndex;
}

int Vocabulary::Get(const std::string & token)
{
	std::map<std::string, int>::const_iterator it = _vocabulary.find(token);

	if (it != _vocabulary.end())
	{
		return _vocabulary[token];
	}
		
	return -1;
}

int Vocabulary::GetSize()
{
	return -1;
}