#include <filter.hpp>
#include <base64.hpp>

#include <opencv2/opencv.hpp>

#include <algorithm>

using namespace Core;

std::string Filter::gaussian(std::string &image_png) {

    auto image_png_vector = std::vector<char>(image_png.begin(), image_png.end());
    auto image = cv::imdecode(image_png_vector, cv::IMREAD_ANYCOLOR | cv::IMREAD_ANYDEPTH);
    auto target_image = image.clone();

    cv::GaussianBlur(image, target_image, cv::Size(5,5), 0, 0);

    std::vector<uchar> buffer;
    cv::imencode(".jpg", target_image, buffer);

    auto buffer_string = std::string(buffer.begin(), buffer.end());
    auto buffer_base64 = Helpers::Base64::Encode(buffer_string);

    return  buffer_string;
}