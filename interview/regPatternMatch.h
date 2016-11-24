/*
A function that supports regular expression . * ? 
*/

#include <string>
using namespace std;

bool regMatch(string src, char pattern);

bool regMatch(string src, string pattern)
{
	if (src.size() == 0 && pattern.size() == 0)
		return true;

	if (pattern.size() == 1){
		
		// pattern[0] should be '.' or a character
		if (
			(pattern[0] == '.' && src.size() == 1)
			|| (pattern[0] == src[0])
			){

			return true;

		}
		else
			return false;
	}

	
	
	// when pattern.size() >= 2
	string src_head, pattern_head, src_tail, pattern_tail;
	bool result;

	if (pattern[1] != '*' && pattern[1] != '?'){
		src_head = src.substr(0,1);
		pattern_head = pattern.substr(0,1);
		src_tail = src.substr(1);
		pattern_tail = pattern.substr(1);
		result = regMatch(src_head, pattern_head);
		result = result & regMatch(src_tail, pattern_tail);
		return result;
	}

	else if (pattern[1] == '?') {
		src_head = src.substr(0, 1);
		pattern_head = pattern.substr(0, 2);
		src_tail = src.substr(1);
		pattern_tail = pattern.substr(2);
		if (!regMatch(src_head, pattern_head[0]))
			result = regMatch(src, pattern_tail);
		else
			result = regMatch(src_tail, pattern_tail);
		return result;
	}

	else if (pattern[1] == '*') {
		src_head = src.substr(0, 1);
		pattern_head = pattern.substr(0, 2);
		src_tail = src.substr(1);
		pattern_tail = pattern.substr(2);
		if (!regMatch(src_head, pattern_head[0])){
			result = regMatch(src, pattern_tail);
		}
		else {

			while (regMatch(src_tail.substr(0, 1), pattern_head[0])){
				
				if (src_tail.size() == 1){
					src_tail = "";
					break;
				}
	
				src_tail = src_tail.substr(1);

			}

			result = regMatch(src_tail, pattern_tail);

		}

		return result;
	}

}

bool regMatch(string src, char pattern)
{
	string szPattern; szPattern.push_back(pattern);
	return regMatch(src, szPattern);
}


void test()
{
	string src, pattern;
	bool result;

	src = "abcde";
	pattern = "b?bb..e";
	result = regMatch(src, pattern);

	src = "abcde";
	pattern = "abs?c.*";
	result = regMatch(src, pattern);


	int ep = 0;
}
