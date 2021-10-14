# Embedded Camera Project
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE) 

## Obtain images of a passing car using a camera connected to an embedded device and send them to a cloud storage service for further analysis

### 1. Introduction 

Main purpose of this demo is to provide a way of obtaining data to train a machine learning model that can automatically detect big to medium size bumps or scratches on cars. An ideal scenario can be the production line of a car manufacturer. As the car is passing by, the videocameras will obtain live footage and create frames. These frames can be stored locally but depending on the embedded device used, the available space might be reduced. 

### 2. Strategy

My strategy is to provide the embedded device with an internet connection (Ethernet or WiFI) and upload the images to a cloud storage service. In this case the chosen cloud provider is Microsoft Azure and the service Azure Storage Explorer.

The stored images can then be used for example on Azure Machine Learning. A serverless function can also be implemented to be triggerd every time a new pictured is stored on the Blob Storage account and send it to signal processing backend service running on the cloud. They could also be sent to a CosmosDB or MongoDB cloud database. Using Data Factory the images can also be sent to on-premises computers that perform further signal processing or training of a ML model.

### 3. Image Pre-Processing on the embedded device

Depending on the embedded device some image pre-processing can be performed on the frames obtained before sending them to the cloud service. In this case the **Canny Edge Detector** is implemented using the **OpenCV** library. Edge Detection can help determine scratches on  surfaces. On the following example we can appreciate the effect of the Canny Detector:

![Example of a frame without any processing](/frames/frame_793.png)
![Example of a frame with Canny Edge processing](/frames_canny/frame_793.png)




### 4. Compiler version
- [gcc 9.3.0](https://packages.ubuntu.com/focal/g++-9-x86-64-linux-gnu) - Running on an Ubuntu distribution with x86_64 architecture

### 5. Covered Technologies and Libraries 
- [C++]
- [Bash Scripting]
- [CMake] - For the generation of the Makefile
- [OpenCV](https://opencv.org/)
