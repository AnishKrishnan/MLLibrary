#include "StringTokenizer.h"

StringTokenizer::StringTokenizer(uint8_t minTokenLength)
{
	_minTokenLength = minTokenLength;
}

void StringTokenizer::Tokenize(std::string text, std::vector<std::string> & tokenizedString)
{
	boost::tokenizer<> token(text);

	for (boost::tokenizer<>::iterator it = token.begin(); it != token.end(); it++)
	{
		tokenizedString.push_back(*it);
	}
}