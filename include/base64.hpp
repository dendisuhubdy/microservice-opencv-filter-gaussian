#ifndef _BASE64_H_
#define _BASE64_H_

#include <string>

namespace Helpers {

    class Base64 {
        public:
            static std::string Encode(const std::string &data);
            static std::string Decode(const std::string &data);
    };
}

#endif