#include "CountVectorizer.h"

CountVectorizer::CountVectorizer(ITokenizer * tokenizer) : _vocab()
{
	this->_tokenizer = tokenizer;
}

void CountVectorizer::Fit(const std::vector<std::string> & corpus)
{
	std::vector<std::string> tokens;

	for (std::vector<std::string>::const_iterator outerIt = corpus.begin(); outerIt != corpus.end(); outerIt++)
	{
		_tokenizer->Tokenize(*outerIt, tokens);
		for (std::vector<std::string>::iterator it = tokens.begin(); it != tokens.end(); it++)
		{
			_vocab.Add(*it);
		}
		tokens.clear();
	}
}

IVocabulary * CountVectorizer::GetVocabulary()
{
	return &_vocab;
}