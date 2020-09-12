#ifndef ERROR_H
#define ERROR_H

#import <iostream>

class Exception {
    protected:
        std::string message = "Exception occurred";
        unsigned int char_pos;
    public:
        std::string getMessage();
        int getCharPos();
};

class ParsingException : public Exception {
    protected:
        std::string message = "Parsing exception occurred";
    public:
        ParsingException(int char_pos);
};

#endif