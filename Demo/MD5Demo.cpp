#include"MD5.h"

int main()
{
	//用于存放字符串化的MD5值
	char strEn[CHAR_MD5_LEN];
	//用于进行错误的字符串校验测试
	char ss[] = "adf7877ea210";


	//MD5编码short数据值
	MD5::MD5Encode("china",strlen("china"),strEn);
	cout << "char 数据：";
	cout << strEn;


	cout << "\n";
	//md5 str校验比较
	if (MD5::MD5StrValidate(strEn, ss))
		cout << "str校验成功";
	else
		cout << "str校验失败";
	cout << "\n";
	if(MD5::MD5StrValidate(strEn,"8a7d7ba288ca0f0ea1ecf975b026e8e1"))
		cout << "str校验成功";
	else
		cout << "str校验失败";
	return 0;
}
