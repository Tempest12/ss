#ifndef _UTIL_HASHTYPES_HPP
#define _UTIL_HASHTYPES_HPP

#include <string>
#include <unordered_map>

namespace Util
{
    //Forward Declarations:
    namespace StringLib
    {
        class Hasher;
        class KeyEquals;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Basic Types:
    typedef std::unordered_map<std::string, std::string, StringLib::Hasher, StringLib::KeyEquals> StringToStringHash;
}

#endif