/*
QT常用函数集合
Copyright(c) 2022  吴珩
Company: 无锡威莱斯电子有限公司

第1次修改：2022.6.10，添加了（1-8）等函数
第2次修改：2022.6.14，新增了（a-d）等函数
第3次修改：2022.6.16，新增了(9-11)、(e)等函数
*/

#ifndef QTCOMMONFUNCTION
#define QTCOMMONFUNCTION

#include "QtCommonHeader_console.h"
//OpenCV头文件
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>  
#include <opencv2/imgproc/imgproc.hpp>
#include<opencv2/videoio.hpp>

//1)获得exe程序的运行路径
QString F_getCurRunPath();

//2)获得exe程序的运行上一级路径
QString F_getCurUpPath();
//当前路径上一级路径
QString F_curUpPath(QString temp_path);

//3)文件夹是否存在
bool F_isDirExist(QString dir_path);

//4)文件是否存在
bool F_isFileExist(QString file_path);

//5)创建文件夹
bool F_createDir(QString dir_path);

//6)创建文件:文件路径、文件名
bool F_createFile(QString file_path);

//7)读取配置文件参数
bool F_loadQstring_INI(QString INI_Path, QString Key_Name, QString Elem_Name, QString& param);
bool F_loadInt_INI(QString INI_Path, QString Key_Name, QString Elem_Name, int& param);
bool F_loadBool_INI(QString INI_Path, QString Key_Name, QString Elem_Name, bool& param);
bool F_loadFloat_INI(QString INI_Path, QString Key_Name, QString Elem_Name, float& param);

//8)保存配置文件参数
void F_saveQstring_INI(QString INI_Path, QString Key_Name, QString Elem_Name, QString param);
void F_saveInt_INI(QString INI_Path, QString Key_Name, QString Elem_Name, int param);
void F_saveBool_INI(QString INI_Path, QString Key_Name, QString Elem_Name, bool param);
void F_saveFloat_INI(QString INI_Path, QString Key_Name, QString Elem_Name, float param, int dot_number=4);

//9)QString与string互转(不存在中文乱码)
std::string F_qstr2str(const QString qstr);
QString F_str2qstr(const std::string str);

//10)读取文件夹下所有的图像
std::vector<std::string> F_loadFileImages(QString file_path);

//11）计算时间戳ms
int F_differQDataTime(QDateTime  t1, QDateTime  t2);

//12）获取文件夹下所有的子文件夹
std::vector<QString> F_getChildNames(QString file_path);

//13）读取相机内参
bool F_loadCameraIntrinsics(QString config_path, float& fx, float& fy, float& cx, float& cy);

//14）读取相机设置参数
bool F_loadCameraParam(QString path, QString& cam_id,
	bool& cam_vertical, bool& cam_level, int& cam_near, int& cam_far);

//15）读取txt文件每一行
std::vector<QString> F_loadTxtLines(QString txt_file);


/*相机相关*/
//a)gamma增强
void F_gammaTransform(const cv::Mat srcImage, cv::Mat& dstImage, double gamma);

//b)灰度图像转伪彩图像
cv::Mat F_grayToRGB(cv::Mat frame_gray, float nearDist, float farDist);

//c)灰度转bgr
void F_assignRGB(int pixel_value, int &red, int &green, int &blue, float nearDist, float farDist);

//d)画出特征点
void F_drawFace(cv::Mat& temp_frame, std::vector<cv::Point> temp_points);
void F_drawPose(cv::Mat& temp_frame, std::vector<cv::Point> temp_points);
void F_drawHand(cv::Mat& temp_frame, std::vector<cv::Point> temp_points, cv::Scalar temp_color = cv::Scalar(0, 0, 255));

#endif QTCOMMONFUNCTION