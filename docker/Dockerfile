## Dockerfile is a definition of how to build the image
# it will take some time to build the image...
FROM arm64v8/ubuntu:16.04
#ENV OPENCV_VERSION 3.4.2

#RUN apt-get update
## install all dependencies
RUN apt-get update && apt-get install -y \
        build-essential \
        cmake \
        pkg-config \
        libgtk-3-dev \
        libomp-dev \
        git \
        v4l-utils \
        libv4l-dev \
        libjson-c-dev \
        libopencv-dev \
        libudev-dev \ 
        nano

## install OpenCV, prepare build, install
RUN mkdir ~/opencv_build && cd ~/opencv_build \
&& git clone https://github.com/opencv/opencv.git \
&& cd opencv \
&& git checkout 3.4.2 \
&& mkdir build && cd build \
&& cmake -D CMAKE_BUILD_TYPE=RELEASE \
        -D CMAKE_INSTALL_PREFIX=/usr/local \
        -D WITH_TBB=ON \
        -D BUILD_NEW_PYTHON_EXAMPLES=ON \
        -D BUILD_EXAMPLES=ON \
        -D WITH_OPENGL=ON \
        -D WITH_GTK=ON \
        -D WITH_GTK3=ON \
        -D WITH_GTK_2_X=OFF .. \
&& make -j6 && make install -j6 \
&& sh -c 'echo "/usr/local/lib" >> /etc/ld.so.conf.d/opencv.conf' \
&& ldconfig \
&& git clone https://github.com/angsa-robotics/linux_camera_tool