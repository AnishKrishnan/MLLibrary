#include "StringTokenizer.h"

StringTokenizer::StringTokenizer(uint8_t minTokenLength)
{
	this->_minTokenLength = minTokenLength;
}

void StringTokenizer::Tokenize(std::string text, std::vector<std::string> & tokenizedString)
{
	boost::tokenizer<> token(text);

	for (boost::tokenizer<>::iterator it = token.begin(); it != token.end(); it++)
	{
		if ((*it).size() >= this->_minTokenLength)
		{
			tokenizedString.push_back(*it);	
		}
	}
}