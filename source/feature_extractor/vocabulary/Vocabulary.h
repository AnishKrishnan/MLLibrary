/** \addtogroup FeatureExtractor
 *  @{
 * Class for the storage of a vocabulary.
 */

#ifndef Vocabulary_H
#define Vocabulary_H

#include <stdio.h>
#include <stdint.h>
#include <map>
#include "IVocabulary.h"

class Vocabulary : public IVocabulary
{
public:

	/**
	 * @brief Constructor for Vocabulary
	 */
	Vocabulary();

	virtual int Add (const std::string & token);

	virtual int Get (const std::string & token);

	virtual int GetSize ();

private:

	std::map<std::string, int> _vocabulary;
	int _currentIndexValue;
};

#endif //Vocabulary_H
/** @}*/