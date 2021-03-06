#ifndef MD5_H
#define MD5_H

#include<iostream>
#include<string>
#include<cstring>
#include"DefHead.h"

#define SHORT_MD5_LEN 16
#define CHAR_MD5_LEN  34


class MD5
{
public:
	explicit MD5();
	static void MD5Encode
	(
		_In_ const char* text,
		_In_ size_t len,
		_Inout_ char* dst
	);

	static bool MD5StrValidate
	(
		_In_ const char* input1,
		_In_ const char* input2
	);
private:
	;
};

#endif // !MD5_H
