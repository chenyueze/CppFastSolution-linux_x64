#include"RSA.h"

RSA::RSA()
{
    ;
}

void RSA::getKey
(
    _Inout_ std::string& public_key,
    _Inout_ std::string& private_key,
    _Inout_ std::string& n
)
{
    mpz_t key_p, key_q, temp_n;
    mpz_t fi, pub_key, pri_key;
    //��ʼ��p,q,n,��(n),��Կ��˽Կ
    mpz_init(key_p);
    mpz_init(key_q);
    mpz_init(temp_n);
    mpz_init(fi);
    mpz_init(pub_key);
    mpz_init(pri_key);
    /*
    *��������1024λ����
    **/
   //����������
    gmp_randstate_t grat;
    //Ĭ����������������Ч��֮��ȡһ������
    gmp_randinit_default(grat);
    //�Ե�ǰʱ����Ϊ����������
    gmp_randseed_ui(grat,time(NULL));
    //����������1024λ����������
    mpz_urandomb(key_p,grat,1024);
    mpz_urandomb(key_q,grat,1024);
    //��������
    mpz_nextprime(key_p,key_p);
    mpz_nextprime(key_q,key_q);
    /*
    *����n����(n)
    **/
    //p��q�õ�n
    mpz_mul(temp_n,key_q,key_p);
    //p,q�ֱ���һ�����˵õ���(n),
    //ע����β��ui��ʾ32λ�޷�������
    mpz_sub_ui(key_p,key_p,1);
    mpz_sub_ui(key_q,key_q,1);
    mpz_mul(fi,key_q,key_p);
    /*�õ���Կe��ֵ��ȡ65537��17��37��47
    *,��Ҫע�⣬��ֵ��65537��������Сֵ
    *����Կ�õ��������ǹ̶������ģ�Ҳ����˵��ȫ���ǲ��ɿ���
    **/
    mpz_set_ui(pub_key,65537);

    //��Ԫ����
    mpz_invert(pri_key,pub_key,fi);
    //����Կ˽Կ��n��Ϊ�ַ���
    mpz_class temp_d(pri_key);
    mpz_class swap_n(temp_n);
    mpz_class temp_e(pub_key);
    public_key=temp_e.get_str();
    private_key=temp_d.get_str();
    n=swap_n.get_str();

    mpz_clear(key_p);
    mpz_clear(key_q);
    mpz_clear(temp_n);
    mpz_clear(fi);
    mpz_clear(pub_key);
    mpz_clear(pri_key);
}

std::string RSA::RSA_Encode
(
    _In_ const char* IN_Data,
     _Inout_ size_t& inoutLen,
    _In_ std::string public_key,
    _In_ std::string n
)
{
    mpz_t m,pub_e,temp_n;
    mpz_init(m);
    mpz_init(pub_e);
    mpz_init(temp_n);
    //ȡ�ù�Կ��n�����ģ�����������ͳһת��Ϊ/mpz_t�߾�������
    mpz_set_str(pub_e,public_key.c_str(),10);
    mpz_set_str(temp_n,n.c_str(),10);
    std::string out_data;
    //���ַ���ѭ�����ܣ����ûس�����
    for(int i=0;i<inoutLen;i++)
    {
        mpz_set_ui(m,(unsigned long)IN_Data[i]);
        /*
        *ģ�ݲ�����ȡ����
        *c=(m^e) mod n
        **/
        mpz_powm(m,m,pub_e,temp_n);
        //ȡ���ַ���
        mpz_class c_data(m);
        out_data.append(c_data.get_str());
        out_data.append("\n");
    }
    inoutLen=out_data.length();

    mpz_clear(m);
    mpz_clear(pub_e);
    mpz_clear(temp_n);
    return out_data;
}

std::string RSA::RSA_Decode
(
    _In_ std::string private_key,
    _In_ std::string n,
    _In_ std::string c_data,
    _Inout_ size_t& inoutLen
)
{
    vector<std::string>C_List;
    std::string temp_str;
    cout<<"\n\n\n\n\n\n";
    //ѭ�������ַ���������ԭ���ַ���������Ϊ�ַ��������б�
    //�Դ˰�˳����������
    for(int i=0;i<inoutLen;i++)
    {
        if(c_data.at(i)=='\n')
        {
            C_List.push_back(temp_str);
            temp_str.clear();
            continue;
        }
        temp_str+=c_data.at(i);
    }
    //cout<<"list\n\n"<<C_List.at(0);

    mpz_t pri_key,temp_n,C_Data;
    mpz_init(pri_key);
    mpz_init(temp_n);
    mpz_init(C_Data);
    //���ַ���תΪmpz_t�߾�������
    mpz_set_str(pri_key,private_key.c_str(),10);
    mpz_set_str(temp_n,n.c_str(),10);
    std::string back_data;
    //ѭ�����������������ж�ԭ���м����ַ���
    //���������Ľ���Ϊ����
    for(int i=0;i<C_List.size();i++)
    {
        mpz_set_str(C_Data,C_List.at(i).c_str(),10);
        mpz_powm(C_Data,C_Data,pri_key,temp_n);
        mpz_class CD(C_Data);
        unsigned long lchar=CD.get_ui();
        char words=(char)lchar;
        back_data+=words;
    }
    inoutLen=back_data.length();
    mpz_clear(pri_key);
    mpz_clear(temp_n);
    mpz_clear(C_Data);
    return back_data;
}
