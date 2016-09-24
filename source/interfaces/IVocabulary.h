/** \addtogroup Interfaces
 *  @{
 * interface for the vocabulary class
 */
 
#ifndef IVocabulary_H
#define IVocabulary_H

#include <stdio.h>
#include <string>

class IVocabulary
{
public:
	virtual ~IVocabulary() {}
	
	/**
	 * @brief Add a word to the vocubulary. 
	 * @detail Returns the index of the word in the vocabulary.
	 */
	 virtual int Add (const std::string & token) = 0;

	 /**
	 * @brief Gets the index of a word in the vocabulary. 
	 * @detail If the word does not exist, returns -1
	 */
	 virtual int Get (const std::string & token) = 0;

	 /**
	 * @brief Gets the size of the vocabulary.
	 */
	 virtual int GetSize () = 0;
};

#endif //IVocabulary_H

 /** @}*/