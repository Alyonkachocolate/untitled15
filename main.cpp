#include <iostream>
#include <string>
#include <random>
#include <bitset>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::bitset;

int main() {
    setlocale( LC_ALL,"Russian" );
    unsigned int VI=485;
    std::uniform_int_distribution<> range{0, 0xFFF};
    std::default_random_engine random_number_generator(VI);
//шифрование
    string s,cipher;
    cin>>s;
    int len=s.length();
    char c;
    if (len%2!=0)
    {
        s[len]=206; //код 206
        c=s[len];
    }
    int i=0;
    while (i<len)
    {
        if (i+1!=len)
        {
            unsigned short cc=((unsigned short)s[i]<<8)|((unsigned short)s[i+1]);
            //cout<<"cc= "<<bitset<16>(cc)<<endl;
            short random_number = range(random_number_generator);
            //cout<<"rd= "<<bitset<16>(random_number)<<endl;
            unsigned short d;
            d=cc^random_number;
            //cout<<"d1= "<<bitset<16>(d)<<endl;
            d=(d>>4)|(d<<(12));
            //cout<<"d2= "<<bitset<16>(d)<<endl;
            unsigned char c1=d>>8;
            //cout<<"c1= "<<bitset<16>(c1)<<endl;
            cipher.push_back(c1);
            unsigned char c2 = d;
            //cout<<"c2= "<<bitset<16>(c2)<<endl;
            cipher.push_back(c2);
        }
        else
        {
            unsigned short cc=((unsigned short)s[i]<<8)|((unsigned short)s[i+1]);
            cout<<"cc= "<<bitset<16>(cc)<<endl;
            short random_number = range(random_number_generator);
            cout<<"rd= "<<bitset<16>(random_number)<<endl;
            unsigned short d;
            d=cc^random_number;
            cout<<"d1= "<<bitset<16>(d)<<endl;
            d=(d>>4)|(d<<(12));
            cout<<"d2= "<<bitset<16>(d)<<endl;
            unsigned char c1=d>>8;
            cout<<"c1= "<<bitset<16>(c1)<<endl;
            cipher.push_back(c1);
        }
        i+=2;
    }
    cout<<"сipher:"<<cipher<<endl;
//    cout<<"сipher:"<<cipher[1]<<endl;
//    cout<<"(short)cipher[0]="<<(unsigned short)cipher[0]<<' '<<"(short)cipher[1]="<<(unsigned short)cipher[1]<<endl;
//    cout<<"cipher.length()="<<cipher.length()<<endl;


//    string s1;
//    s1=cipher;
//    cout<<s1<<endl;
//    string plaintext;
//    int len1=s1.length();
//    if (len1%2!=0)
//    {
//        s[len1]=206; //код 206
//        c=s[len1];
//    }
//    i=0;
//    while (i<len1)
//    {
//        if (s1[i+1]!=s1[len1])
//        {
//            unsigned short cc=((unsigned short)s1[i]<<8);
//            cout<<"cc= "<<bitset<16>(cc)<<endl;
//            short random_number = range(random_number_generator);
//            cout<<"rd= "<<bitset<16>(random_number)<<endl;
//            unsigned short d;
//            d=(cc<<4)|(cc>>(12));
//            cout<<"d1= "<<bitset<16>(d)<<endl;
//            d=d^random_number;
//            cout<<"d2= "<<bitset<16>(d)<<endl;
//            unsigned char c1=d>>8;
//            cout<<"c1= "<<bitset<16>(c1)<<endl;
//            plaintext.push_back(c1);
//            unsigned char c2 = d;
//            cout<<"c2= "<<bitset<16>(c2)<<endl;
//            plaintext.push_back(c2);
//        }
//        else
//        {
//            unsigned short cc=((unsigned short)s1[i]<<8);
//            cout<<"cc= "<<bitset<16>(cc)<<endl;
//            short random_number = range(random_number_generator);
//            cout<<"rd= "<<bitset<16>(random_number)<<endl;
//            unsigned short d;
//            d=(cc<<4)|(cc>>(12));
//            cout<<"d1= "<<bitset<16>(d)<<endl;
//            d=d^random_number;
//            cout<<"d2= "<<bitset<16>(d)<<endl;
//            unsigned char c1=d>>8;
//            cout<<"c1= "<<bitset<16>(c1)<<endl;
//            plaintext.push_back(c1);
//        }
//        i+=2;
//    }
//    cout<<"plaintext:"<<plaintext<<endl;



//расшивровка
//    string s,cipher;
//    cin>>s;
//    int len=s.length();
//    char c;
//
//string s1;
//    s1=cipher;
//    cout<<s1<<endl;
//    string plaintext;
//    int len1=s1.length();
//    if (len1%2!=0)
//    {
//        s[len1]=206; //код 206
//        c=s[len1];
//    }
//    i=0;
//    while (i<len1)
//    {
//        if (s1[i+1]!=s1[len1])
//        {
//            unsigned short cc=((unsigned short)s1[i]<<8)|((unsigned short)s1[i+1]);
//            cout<<"cc= "<<bitset<16>(cc)<<endl;
//            short random_number = range(random_number_generator);
//            cout<<"rd= "<<bitset<16>(random_number)<<endl;
//            unsigned short d;
//            d=(cc<<4)|(cc>>(12));
//            cout<<"d1= "<<bitset<16>(d)<<endl;
//            d=d^random_number;
//            cout<<"d2= "<<bitset<16>(d)<<endl;
//            unsigned char c1=d>>8;
//            cout<<"c1= "<<bitset<16>(c1)<<endl;
//            plaintext.push_back(c1);
//            unsigned char c2 = d;
//            cout<<"c2= "<<bitset<16>(c2)<<endl;
//            plaintext.push_back(c2);
//        }
//        else
//            {
//                unsigned short cc=((unsigned short)s1[i]<<8);
//                cout<<"cc= "<<bitset<16>(cc)<<endl;
//                short random_number = range(random_number_generator);
//                cout<<"rd= "<<bitset<16>(random_number)<<endl;
//                unsigned short d;
//                d=(cc<<4)|(cc>>(12));
//                cout<<"d1= "<<bitset<16>(d)<<endl;
//                d=d^random_number;
//                cout<<"d2= "<<bitset<16>(d)<<endl;
//                unsigned char c1=d>>8;
//                cout<<"c1= "<<bitset<16>(c1)<<endl;
//                plaintext.push_back(c1);
//            }
//        i+=2;
//    }
//    cout<<"plaintext:"<<plaintext<<endl;

    //cout<<"d1= "<<bitset<16>(d)<<endl;
    return 0;
}

// c1= 0000000011001111