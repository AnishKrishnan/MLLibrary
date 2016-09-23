/** \addtogroup FeatureExtractor
 *  @{
 * Class to create a tokenize text features from a string
 */

#ifndef StringTokenizer_H
#define StringTokenizer_H

#include <boost/tokenizer.hpp>
#include <stdio.h>

class StringTokenizer 
{
public:

	/**
	 * @brief Constructor for StringTokenizer
	 */
	StringTokenizer();

	/**
	 * @brief Tokenizes the input text into the output vector.
	 */
	void Tokenize(std::string text, std::vector<std::string> & tokenizedString);
};

#endif //StringTokenizer_H
/** @}*/