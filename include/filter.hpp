#ifndef _FILTER_H_
#define _FILTER_H_

#include <string>

namespace Core {
    class Filter {
        public:
            static std::string gaussian(std::string & b64_png_image);
    };
}

#endif