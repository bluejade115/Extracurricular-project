# Extracurricular-project
本科期间的完成的一些项目，主要涉及嵌入式、基于深度学习的计算机视觉、基于ROS的机器人开发、具身智能等项目

## 大一期间
### 知识和技能学习
大一期间，我主要学习STM32、EDA、FreeRTOS等嵌入式相关的知识。
### 基于STM32的红外检测的循迹小车
- **背景**:本项目是聚徒课程的结课任务，个人完成红外检测的循迹小车的开发。
- **技术细节**:读取红外检测模块的检测结果，根据检测结果，通过PWM完成差速控制小车点击完成转向、加速等功能。
- **代码**:[基于STM32的红外检测的循迹小车](Infrared-Line-Tracking-Vehicle/)
- **演示demo**
  
[循迹小车演示demo](https://github.com/user-attachments/assets/b56040be-90e1-4e44-83ad-860a2a5d940c)



## 大二期间
### 知识和技能学习
大二期间，我主要学习基于以下知识：
- 基于Pytorch的计算机视觉模型开发（如YOLO，RT-DETR，ResNet）
- 基于ROS的Navigation Stack开发
- 视觉SLAM建图（如ORBSLAM、RTABMap）
- 基于webots的机械臂开发
### 基于Jetson Xavier NX和Yolo11的仪表盘目标检测
- **背景**:本项目是为[2025年中国高校智能机器人创意大赛--省赛](https://www.robotcontest.cn/home/homepage)而准备的。任务内容是在Jetson Xavier NX上完成仪表盘状态的检测。
- **技术细节**:我们完成在[Roboflow](https://universe.roboflow.com/)网站完成制作数据集。由于任务简单，我们采取基于YOLO11n-cls的图片分类的方案。我们使用Ultralytics提供docker镜像在Jetson Xavier NX完成Yolo环境的配置，并且使用TensorRT进行加速。
- **代码**:
- **数据集**：[中国高校智能机器人创意大赛--仪表盘](https://universe.roboflow.com/wendychen/dashboard-wso6u)
- **演示demo**:

### 基于Jetson Xavier NX的机器狗的视觉导航和目标检测
- **背景**：本项目是为[2025年中国高校智能机器人创意大赛--国赛(https://www.robotcontest.cn/home/homepage)而准备的。任务内容是绝影Lite3机器狗自主完成巡检和识别任务。
- **技术细节**：
- **代码**：
- **数据集**：[中国高校智能机器人创意大赛--仪表盘、数字、锥形桶识别等数据集](https://universe.roboflow.com/wendychen/dashboard_seg)
- **演示demo**：
### 基于MoveIt2的机械臂的仿真抓取
- **背景**：
- **技术细节**：
- **代码**：
- **数据集**：
- **演示demo**：
### 基于Gazebo仿真的小车的雷达SLAM导航和目标检测
- **背景**：
- **技术细节**：
- **代码**：
- **数据集**：[全球校园人工智能算法精英大赛--人物模型、车牌数据集](https://universe.roboflow.com/wendychen/detectpeople-obpao)
- **演示demo**：
### 基于Jetson Orin Nano的小车的雷达SLAM导航和目标检测
- **背景**：
- **技术细节**：
- **代码**：
- **数据集**：[全球校园人工智能算法精英大赛--人物模型、车牌、红绿灯等数据集](https://universe.roboflow.com/wendychen/realsence_detect-3-kjf3p)
- **演示demo**：
## 大三期间
### 基于GR00T N1.5-3B和Lerobot SO101的桌面清理机器人
- **背景**:本项目是为由Seeed & Nvidia & HuggingFace联合举办的[2025 具身智能黑客松-深圳站](https://www.seeedstudio.com.cn/post/%E6%8E%A2%E7%B4%A2%E5%85%B7%E8%BA%AB%E6%99%BA%E8%83%BD%E7%9A%84%E6%9C%AA%E6%9D%A5%EF%BC%9A2025-seeed-embodied-ai-%E9%BB%91%E5%AE%A2%E6%9D%BE-%E6%B7%B1%E5%9C%B3%E7%AB%99)而准备的桌面清理机器人。
- **技术细节**:我们采用在仿真（Isaac Sim and Mujoco）+现实的遥操作采集数据，共300份数据。使用采集到的数据在GR00T N1.5-3B模型上进行微调，启用Diffusion+ 35k Steps在A6000上进行训练，大约花费9小时。在RTX 4090和Jetson Thor上完成部署进行推理。在4090上的单次平均推理耗时是55.67ms，在Jetson Thor的单次推理耗时是118.12ms。
- **项目特点**:本项目荣获本次黑客松活动第一名。获奖理由是泛化性强（能够抓取训练集之外的笔、螺丝刀等）、机械臂运行流畅、抓取准确率高等。
- **项目演示**
  ![微信图片_20251023150728_60_2](https://github.com/user-attachments/assets/48d40a00-f340-4041-9f88-899f7b1b4944)
  
  [在Jetson Thor部署的demo](https://github.com/user-attachments/assets/7e9745f7-275e-495b-9a33-37e8e8445228)
  

