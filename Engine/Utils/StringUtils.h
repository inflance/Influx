//
// Created by liyun on 24-6-29.
//

#ifndef STRINGUTILS_HPP
#define STRINGUTILS_HPP

#include <string>
#include <vector>

#include "Engine/Core/Export.h"

namespace influx {
	/**
	* The StringUtils class provides utility functions for string manipulation
	*/
	class INFLUX_API StringUtils {
	public:
		/**
		 *
		 * @param str The string to convert to lowercase
		 * @return The lowercase string
		 */
		static std::string ToLower(const std::string &str);

		/**
		 *
		 * @param str  The string to convert to uppercase
		 * @return The uppercase string
		 */
		static std::string ToUpper(const std::string &str);

		/**
		 *
		 * @param str  The string to trim
		 * @return  The trimmed string
		 */
		static std::string Trim(const std::string &str);

		/**
		 *
		 * @param str  The string to split
		 * @param delim The delimiter to split the string by
		 * @return The vector of strings after splitting the string
		 */
		static std::vector<std::string> Split(const std::string &str, const std::string &delim);

		/**
		 *
		 * @param str The src string to replace
		 * @param from The sub string to replace
		 * @param to The sub string to replace with
		 * @return The replaced string
		 */
		static std::string Replace(const std::string &str, const std::string &from, const std::string &to);

		/**
		 *
		 * @param str  The src string to remove
		 * @param to_remove The sub string need to remove
		 * @return The removed string
		 */
		static std::string Remove(const std::string &str, const std::string &to_remove);

		/**
		 *
		 * @param str  The src string to remove
		 * @param to_remove The sub string need to remove
		 * @return The removed string
		 */
		static std::string Remove(const std::string &str, const char &to_remove);

		/**
		 * 
		 * @param strings  The vector of strings to join
		 * @param delim  The delimiter to join the strings by
		 * @return  The joined string
		 */
		static std::string Join(const std::vector<std::string> &strings, const std::string &delim);
	};
} // influx

#endif //STRINGUTILS_HPP
