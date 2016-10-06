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

IMatrix<int> * CountVectorizer::Transform(const std::vector<std::string> & corpus)
{
	int featureNumber = _vocab.GetSize();
	int documentNumber = corpus.size();

	Matrix<int> * mat = new Matrix<int>(documentNumber, featureNumber);

	int documentIndex = 0;
	std::vector<std::string> tokens;

	for (std::vector<std::string>::const_iterator outerIt = corpus.begin(); outerIt != corpus.end(); outerIt++)
	{
		_tokenizer->Tokenize(*outerIt, tokens);

		for (std::vector<std::string>::iterator it = tokens.begin(); it != tokens.end(); it++)
		{
			int featureIndex  = _vocab.Get(*it);

			if (featureIndex != -1)
			{
				mat->operator()(documentIndex, featureIndex)++;
			}
			else
			{
				mat->operator()(documentIndex, featureIndex) = 0;
			}
		}

		tokens.clear();
		documentIndex++;
	}

	return mat;
}

IVocabulary * CountVectorizer::GetVocabulary()
{
	return &_vocab;
}