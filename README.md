# Readme

## Introduction

This is an example using [Crow](https://github.com/ipkn/crow) library  to serve an OpenCV image filter. This example
users a compiled version of OpenCV 4.0.0 and requires following packages:

- OpenCV 4.0.0
- Crow Library v0.1
- GCC with support to C++17
- Cmake 1.13
- Boost::System

## How to build

After building and install OpenCV 4.0.0, GCC, Cmake and Boost::System you should do following commands

```
git clone https://github.com/arthurafarias/microservice-opencv-filter-gausian
cd microservice-opencv-filter-gausian
git submodule update --init --recursive
mkdir build
cd build
cmake ..
make -$(nproc)
```

### Testing

After initializing by issuing following command

```
./ocv_microservice_crow
```

You should submit a POST request to http://localhost:18080/filters/gaussian. The body of this request should be your
binary PNG image. The response should be a gaussian filtered image from the submited image.