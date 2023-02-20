// 67_ 복사 생성자 오버로딩 실습

#include <iostream>
#pragma warning(disable:4996)

using namespace std;

class String {
public:
    String() {
        strData = NULL;
        len = 0;
    }
    String(const char* str) {
        this->len = strlen(str);
        strData = new char[len + 1]; // NULL 문자를 고려해서 len + 1 만큼 할당
        strcpy(strData, str);
    }
    String(const String &rhs) {
        this->strData = new char[rhs.len + 1];
        strcpy(this->strData, rhs.strData); // 깊은 복사
        len = rhs.len; // 깊은 복사
    }
    String &operator=(const String& rhs) { // 대입(=) 연산자 오버로딩
        if(this != &rhs)
        { 
            delete[] strData;
            this->strData = new char[rhs.len + 1];
            strcpy(this->strData, rhs.strData);
            len = rhs.len;
        }
        return *this;
       
        
    }

    ~String() {
        delete[] strData;
        strData = NULL;
    }
    
    char* GetStrData() const {
        return strData;
    }
    int GetLen() const {
        return len;
    }

private:
    char* strData;
    int len;
};

int main()
{
    String s1("안녕");
    String s2(s1);
    String s3("Hello");
    s3.operator=(s1);
    //s3 = s1;

    cout << s1.GetStrData() << endl;
    cout << s2.GetStrData() << endl;
    cout << s3.GetStrData() << endl;
}