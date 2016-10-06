/** \addtogroup FeatureExtractor
 *  @{
 * Class to vectorize a a corpus of text documents
 */

#ifndef CountVectorizer_H
#define CountVectorizer_H

#include <boost/tokenizer.hpp>
#include <stdio.h>
#include <stdint.h>
#include "ITokenizer.h"
#include "IVectorizer.h"
#include "Vocabulary.h"
#include "Matrix.h"

class CountVectorizer : public IVectorizer<int>
{
public:

	/**
	 * @brief Constructor for CountVectorizer
	 */
	CountVectorizer(ITokenizer * tokenizer);

	/**
	 * @brief Builds a vocubulary from the input corpus of documents.
	 */
	virtual void Fit (const std::vector<std::string> & corpus);

	/**
	* @brief Creates a matrix of features from the corpus of documents based on the current vocabulary
	*/
	virtual IMatrix<int> * Transform (const std::vector<std::string> & corpus);

	/**
	* @brief Gets the current vocabulary
	*/
	virtual IVocabulary * GetVocabulary ();

private:

	ITokenizer * _tokenizer;
	Vocabulary _vocab;
};

#endif //CountVectorizer_H
/** @}*/