/**
 ** Copyright (c) 2011 Illumina, Inc.
 **
 **
 ** This software is covered by the "Illumina Non-Commercial Use Software
 ** and Source Code License Agreement" and any user of this software or
 ** source file is bound by the terms therein (see accompanying file
 ** Illumina_Non-Commercial_Use_Software_and_Source_Code_License_Agreement.pdf)
 **
 ** This file is part of the BEETL software package.
 **
 ** Citation: Markus J. Bauer, Anthony J. Cox and Giovanna Rosone
 ** Lightweight BWT Construction for Very Large String Collections.
 ** Proceedings of CPM 2011, pp.219-231
 **
 **/

#ifndef FILENAME_HH
#define FILENAME_HH

#include <iostream>
#include <string>
#include <sstream>

using std::string;


typedef const char *constCharStar;


class Filename
{
public:
    Filename( const std::string &str )
    {
        str_ = str;
    }

    Filename( const int i )
    {
        std::ostringstream fn;
        fn << i;
        str_ = fn.str();
    }

    Filename( const char *part1, const std::string &part2 )
    {
        std::ostringstream fn;
        fn << part1 << part2;
        str_ = fn.str();
    }

    Filename( const std::string &part1, const int part2, const std::string &part3 = "" )
    {
        std::ostringstream fn;
        fn << part1 << part2 << part3;
        str_ = fn.str();
    }

    Filename( const char *part1, const std::string &part2, const int part3, const std::string &part4 = "" )
    {
        std::ostringstream fn;
        fn << part1 << part2 << part3 << part4;
        str_ = fn.str();
    }

    // automatic cast operator to string
    operator std::string( void ) const
    {
        return str_;
    }

    // automatic cast operator to const char*
    operator constCharStar( void ) const
    {
        return str_.c_str();
    }

    std::string str() const
    {
        return str_;
    }

private:
    string str_;
};

#endif // FILENAME_HH