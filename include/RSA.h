#ifndef RSA_H
#define RSA_H

#include<iostream>
#include "DefHead.h"
#include "C_EncryCore.h"
#include<string>
#include<vector>
#include<time.h>



class RSA:public CEncryCore
{
    public:
        explicit RSA();
        void getKey
        (
            _Inout_ std::string& public_key,
            _Inout_ std::string& private_key,
            _Inout_ std::string& n
        );
        std::string RSA_Encode
        (
            _In_  const char* IN_Data,
            _Inout_ size_t& inoutLen,
            _In_ std::string public_key,
            _In_ std::string n
        );
        std::string RSA_Decode
        (
            _In_ std::string private_key,
            _In_ std::string n,
            _In_ std::string c_data,
            _Inout_ size_t& inoutLen
        );

};
#endif
