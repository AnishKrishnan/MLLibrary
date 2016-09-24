#include "CountVectorizer.h"

CountVectorizer::CountVectorizer(ITokenizer * tokenizer)
{
	this->_tokenizer = tokenizer;
}

void CountVectorizer::Fit(const std::vector<std::string> & corpus)
{

}