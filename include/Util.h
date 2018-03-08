#ifndef UTIL_H
#define UTIL_H


class Util
{
    public:
        /** Default constructor */
        Util();
        /** Default destructor */
        virtual ~Util() = 0;
        static int getCStringSize(const char*);

    protected:

    private:
};

inline int Util::getCStringSize(const char* str){
    const char* ptr = str;
    unsigned int size = 0;
    while(*ptr++){
        size++;
    }
    return size;
}

#endif // UTIL_H
