#include"MD5.h"

int main()
{
	//���ڴ���ַ�������MD5ֵ
	char strEn[CHAR_MD5_LEN];
	//���ڽ��д�����ַ���У�����
	char ss[] = "adf7877ea210";


	//MD5����short����ֵ
	MD5::MD5Encode("china",strlen("china"),strEn);
	cout << "char ���ݣ�";
	cout << strEn;


	cout << "\n";
	//md5 strУ��Ƚ�
	if (MD5::MD5StrValidate(strEn, ss))
		cout << "strУ��ɹ�";
	else
		cout << "strУ��ʧ��";
	cout << "\n";
	if(MD5::MD5StrValidate(strEn,"8a7d7ba288ca0f0ea1ecf975b026e8e1"))
		cout << "strУ��ɹ�";
	else
		cout << "strУ��ʧ��";
	return 0;
}
