class FooString {
    char* buf;
public:
    FooString(char* tbuf);
    ~FooString();
    void show();
    int length();
    bool compare(char* str);
};
