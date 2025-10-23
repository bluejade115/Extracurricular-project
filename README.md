# Extracurricular-project
本科期间的完成的一些项目，主要涉及嵌入式、基于深度学习的计算机视觉、基于ROS的机器人开发、具身智能等项目

## 大一期间
大一期间，我主要学习STM32、EDA、FreeRTOS等嵌入式相关的知识。

我完成了以下项目：
- [基于STM32的红外检测的循迹小车](Infrared-Line-Tracking-Vehicle/)

## 大二期间
大二期间，我主要学习基于以下知识：
- 基于Pytorch的计算机视觉模型开发（如YOLO，RT-DETR，ResNet）
- 基于ROS的Navigation Stack开发
- 视觉SLAM建图（如ORBSLAM、RTABMap）
- 基于webots的机械臂开发

在基于Pytorch的计算机视觉模型开发部分，主要基于YOLO11完成比赛所需的目标检测和分类任务。我全流程完成数据集制作、模型训练及微调、Nvidia Jetson边缘终端设备部署。以下是我完成的内容：
- [中国高校智能机器人创意大赛--仪表盘、数字、锥形桶识别等数据集](https://universe.roboflow.com/wendychen/dashboard_seg)
- [全球校园人工智能算法精英大赛--人物模型、车牌、红绿灯等数据集](https://universe.roboflow.com/wendychen/realsence_detect-3-kjf3p)

## 大三期间
### 基于GR00T N1.5-3B和Lerobot SO101的桌面清理机器人
- **背景** 本项目是为由Seeed & Nvidia & HuggingFace联合举办的[2025 具身智能黑客松-深圳站](https://www.seeedstudio.com.cn/post/%E6%8E%A2%E7%B4%A2%E5%85%B7%E8%BA%AB%E6%99%BA%E8%83%BD%E7%9A%84%E6%9C%AA%E6%9D%A5%EF%BC%9A2025-seeed-embodied-ai-%E9%BB%91%E5%AE%A2%E6%9D%BE-%E6%B7%B1%E5%9C%B3%E7%AB%99)而准备的桌面清理机器人。
- **技术细节** 我们采用在仿真（Isaac Sim and Mujoco）+现实的遥操作采集数据，共300份数据。使用采集到的数据在GR00T N1.5-3B模型上进行微调，启用Diffusion+ 35k Steps在A6000上进行训练，大约花费9小时。在RTX 4090和Jetson Thor上完成部署进行推理。在4090上的单次平均推理耗时是55.67ms，在Jetson Thor的单次推理耗时是118.12ms。
- **项目特点** 本项目荣获本次黑客松活动第一名。获奖理由是泛化性强（能够抓取训练集之外的笔、螺丝刀等）、机械臂运行流畅、抓取准确率高等。
- **项目演示**
  ![微信图片_20251023150728_60_2](https://github.com/user-attachments/assets/48d40a00-f340-4041-9f88-899f7b1b4944)
  
  [在Jetson Thor部署的demo](https://github.com/user-attachments/assets/7e9745f7-275e-495b-9a33-37e8e8445228)
  

