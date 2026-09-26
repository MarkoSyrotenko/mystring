#include <iostream>
#include <string>
using namespace std;

class MyString
{
    char* text;
    int size;
    static int count;
public:
    MyString()
    {
        size = 80;
        text = new char[size+1];

        count++;
    }
    MyString(int s)
    {
        size = s;
        text = new char[size+1];
        count++;
    }
    MyString(char* t)
    {
        size = strlen(t);
        text = new char[size+1];
        strcpy_s(text, size + 1, t);
        count++;
    }
    MyString(const MyString& obj)
    {
        size = obj.size;
        text = new char[size + 1];
        strcpy_s(text, size + 1, obj.text);
        count++;
    }
    ~MyString()
    {
        delete[] text;
        cout << "string deleted\n";
        count--;
    }
    void Print()
    {
        cout << text << endl;
    }
    void SetText(char* t)
    {
        delete[] text;
        size = strlen(t);
        text = new char[size + 1];
        strcpy_s(text, size + 1, t);
    }
    static int GetCount()
    {
        return count;
    }
    MyString operator *(MyString s)
    {
        char* txt;
        txt = new char[100];
        int letter = 0;
        for (int i = 0; i < strlen(text); i++)
        {
            for (int j = 0; j < strlen(s.text); j++)
            {
                if (text[i] == s.text[j])
                {
                    txt[letter] = text[i];
                    letter++;
                    break;
                }
            }
        }
        txt[letter] = '\0';
        MyString str(txt);
        delete[] txt;
        return str;
    }

    void MyStrcpy(MyString& obj)
    {
        delete[] text;
        size = obj.size;
        text = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
            text[i] = obj.text[i];
        }
        text[size] = '\0';
    }
    bool MyStrStr(const char* str)
    {
        int len = strlen(str);
        int index = 0;
        for (int i = 0; i < size; i++)
        {
            if (text[i] == str[index])
                index++;
            if (index = len)
                return true;
        }
        return false;
    }
    int MyChr(char c)
    {
        for (int i = 0; i < size; i++)
        {
            if (text[i] == c)
                return i;
        }
        return -1;
    }
    int MyStrLen()
    {
        for (int i = 0; i < size; i++)
        {
            if (text[i] == '\0')
                return i;
        }
        return size;
    }
    void MyStrCat(MyString& b)
    {
        int newsize = size + b.size;
        char* txt = new char[newsize + 1];
        for (int i = 0; i < size; i++)
        {
            txt[i] = text[i];
        }
        for (int i = 0; i < b.size; i++)
        {
            txt[i+size] = b.text[i];
        }
        txt[newsize] = '\0';
        delete[] text;
        text = txt;
    }
    void operator +=(MyString& b)
    {
        MyStrCat(b);
    }

    void MyDelChr(char c)
    {
        int newsize = size;
        for (int i = 0; i < size; i++)
        {
            if (text[i] == c)
                newsize--;
        }
        char* txt = new char[newsize+1];
        int index = 0;
        for (int i = 0; i < newsize; i++)
        {
            if (text[index] == c)
            {
                i--;
                index ++;
                continue;
            }
            txt[i] = text[index];
            index++;
        }
        delete[] text;
        text = txt;
        size = newsize;
        text[size] = '\0';
    }
    int MyStrCmp(MyString& b)
    {
        int i = 0;
        while (i < size && i < b.size)
        {
            if (text[i] > b.text[i])
                return 1;
            if (text[i] < b.text[i])
                return -1;
            i++;
        }
        if (size > b.size)
            return 1;
        else if (size < b.size)
            return -1;
        else return 0;
    }
    void Input()
    {
        char* input;
        input = new char[1000];
        cout << "enter a string:\n";
        cin >> input;
        size = strlen(input);
        char* txt = new char[size + 1];
        strcpy_s(txt, size + 1, input);
        delete[] text;
        delete[] input;
        text = txt;
    }
};

int MyString::count = 0;

int main()
{

    MyString str1;
    MyString str2;
    str1.Input();
    str2.Input();
    cout << endl;
    str1.Print();
    str2.Print();

    MyString str3;
    str3.MyStrcpy(str1);
    str3.Print();

    cout << "search: ";
    char* strstr = new char[50];
    cin >> strstr;

    cout << str1.MyStrStr(strstr) << endl;
    cout << str1.MyChr('e') << endl;
    cout << str1.MyStrLen() << endl;
    str3 += str2;
    str3.Print();
    str3.MyDelChr('e');
    str3.Print();
    cout << str1.MyStrCmp(str2) << endl;
    cout << str1.GetCount();

    cout << endl;
}