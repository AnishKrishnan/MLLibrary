/** \addtogroup FeatureExtractor
 *  @{
 * Class to create a tokenize text features from a string
 */

#ifndef StringTokenizer_H
#define StringTokenizer_H

#include <boost/tokenizer.hpp>
#include <stdio.h>
#include <stdint.h>

class StringTokenizer 
{
public:

	/**
	 * @brief Constructor for StringTokenizer
	 */
	StringTokenizer(uint8_t minTokenLength = 1);

	/**
	 * @brief Tokenizes the input text into the output vector.
	 */
	void Tokenize(std::string text,	 std::vector<std::string> & tokenizedString);

private:

	uint8_t _minTokenLength;
};

#endif //StringTokenizer_H
/** @}*/