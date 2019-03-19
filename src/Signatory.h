#ifndef SIGNATORY
#define SIGNATORY


#include"identity.h"
#include"Signature.h"

class Signatory{
    Identity identity_data;
    Signature signature_data;
    uint64_t length;
    public:
    Signatory(){
        length = 0;
    }

    ~Signatory(){

    }

    auto Serialize(Byte *buffer, int offset = 0)
    {
        identity_data.Serialize(buffer, offset);
        signature_data.Serialize(buffer, identity_data.getLength()+offset);
        return length;
    }
    
    void Deserialize(Byte *buffer, int position=0)
    {
        identity_data.Deserialize(buffer, position);
        signature_data.Deserialize(buffer, (position + identity_data.getLength()));
        length = (identity_data.getLength()) + (signature_data.getLength());
    }

    void setSignatory(){
        identity_data.SetIdentity();
        signature_data.SetSignature();
        length = identity_data.getLength() + signature_data.getLength();
    }
    
    void printSignatory(){
        cout << "IDENTITY DATA: " <<endl;
        identity_data.PrintIdentity();
        cout << "SIGNATURE DATA: " <<endl;
        signature_data.PrintSignature();
    }

    auto getLength(){
        cout << identity_data.getLength() << endl;
        cout << signature_data.getLength() <<endl;
        return length;
    }
};


#endif