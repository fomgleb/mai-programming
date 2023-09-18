class FooString {
    char* buf;
public:
    FooString(char* tbuf);
    ~FooString();
    void show();
    int length();
    bool compare(FooString& str);
    bool compare(char* str);
    void add(char*);
};
