/** \addtogroup Interfaces
 *  @{
 * interface for teh vectorizer class
 */
 
#ifndef IVectorizer_H
#define IVectorizer_H

#include "IVocabulary.h"

class IVectorizer
{
public:
	virtual ~IVectorizer() {}
	
	/**
	 * @brief Builds a vocabulary from the corpus of documents, represented as strings.
	 */
	 virtual void Fit (const std::vector<std::string> & corpus) = 0;

	 /**
	 * @brief Gets the vocabluary
	 */
	 virtual IVocabulary * GetVocabulary () = 0;
};

#endif //IVectorizer_H

 /** @}*/