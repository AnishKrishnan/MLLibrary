/** \addtogroup Interfaces
 *  @{
 * interface for teh vectorizer class
 */
 
#ifndef IVectorizer_H
#define IVectorizer_H

#include "IVocabulary.h"
#include "IMatrix.h"

template <typename T> class IVectorizer
{
public:
	virtual ~IVectorizer() {}
	
	/**
	 * @brief Builds a vocabulary from the corpus of documents, represented as strings.
	 */
	 virtual void Fit (const std::vector<std::string> & corpus) = 0;

	 /**
	 * @brief Transforms the corpus to a matrix of features, based on the current vocabulary
	 */
	 virtual IMatrix<T> * Transform (const std::vector<std::string> & corpus) = 0;

	 /**
	 * @brief Gets the vocabluary
	 */
	 virtual IVocabulary * GetVocabulary () = 0;
};

#endif //IVectorizer_H

 /** @}*/