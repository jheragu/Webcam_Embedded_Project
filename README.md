# Embedded Vision Project
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE) 

## Obtain images of a passing car using a USB video camera connected to an embedded device and send them to a cloud storage service for further analysis

### 1. Introduction 

The purpose of this demo is to provide a way of obtaining data to train a machine learning model that can automatically detect big to medium size bumps or scratches on cars. A possible scenario can be the production line of a car manufacturer. As the car is passing at some point in the production line, the video cameras will obtain live footage and create frames/images from it. The frames can be stored locally but depending on the embedded device used, the available space might be limited. A malfunction of the device or the attached storage could result in the loss of data. A way of assuring redundancy and replication of the data must be guaranteed.

### 2. Strategy

My strategy is to provide the embedded device with an internet connection (Ethernet or WiFi) and upload the images to a cloud storage service. In this demo, the chosen cloud provider is Microsoft Azure and the service Azure Blob Storage.

ETL Process -> The images stored on the cloud could be directly used to train an ML/DL model on Azure Machine Learning or Databricks. A serverless Azure function can also be implemented to be triggered every time a new image is stored on the Blob Storage account and send it immediately to an image processing backend running on the cloud (VM / Container). The images might also be sent to a CosmosDB or MongoDB cloud database, a Data Warehouse, or on-premises computers using an Azure Data Factory pipeline. Cloud strategy also facilitates the monitoring of the data during all these processes and spares substantial costs on infrastructure maintenance.

### 3. Image Pre-Processing on the embedded device

Depending on the chosen embedded device, some image pre-processing can be performed on the frames obtained before sending them to the cloud service. In the code, an example with the Canny Edge Detector has been implemented using the OpenCV library. Edge Detection can substantially help determine scratches on surfaces. In the following example, a sticker is placed on the left door of a toy car and in the right picture, the result of applying the Canny detector can be seen. The edges of the sticker are successfully recognized.

![Example of a frame without any processing](/frames/frame_793.png)
![Example of a frame with Canny Edge Detector](/frames_canny/frame_793.png)

### 4. Demo

The code is executed under Ubuntu Linux using a webcam camera. A toy car is moved in front of the camera and a new image is taken every 2 seconds. The interval time between taking pictures can be adjusted in code, as well as the size of the images. After an image is saved, the Canny detector is applied to it. The processed image is then sent to Azure using REST API. To avoid possible latency problems uploading data to the internet, an asynchronous function is used. After successfully uploading the image, it should be deleted to avoid possible space problems.


### 5. Compiler
- [gcc 9.3.0](https://packages.ubuntu.com/focal/g++-9-x86-64-linux-gnu) - Running on an Ubuntu distribution with x86_64 architecture
- CMakeList.txt contains the instructions to generate the Makefile.

### 6. Covered Technologies and Libraries 
- [C++]
- [Bash Scripting]
- [CMake] - For the generation of the Makefile
- [OpenCV](https://opencv.org/)
- [Azure CLI]
- [Azure Blob Storage] - with SaS token
