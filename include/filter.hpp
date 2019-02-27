#ifndef _FILTER_H_
#define _FILTER_H_

#include <string>

/**
 * @brief This namespace refers to implementation of core functionalities from the service
 * 
 */
namespace Core {

    /**
     * @brief Filter class reunite just just statich filtering functions that are used to process request bodies
     * 
     */
    class Filter {
        public:

        /**
         * @brief this function uses OpenCV to apply gaussian filter to an image
         * 
         * @param image_data binary data of the image data
         * @return std::string binary png data of filtered image
         */
        static std::string gaussian(std::string & image_data);
    };
}

#endif