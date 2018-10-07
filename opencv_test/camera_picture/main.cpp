#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

#define camera_name "摄像头"
#define picwindow_name "截图图片"

int main()
{
    VideoCapture capture(0);
    if (!capture.isOpened())
    {
        cout << "摄像头打开失败!" << endl;
        return 0;
    }
    Mat frame;
    char key;//按键
    char picture_name[200];//用于存放保存图片的文件名
    int i = 0;//计数
    namedWindow(camera_name);
    namedWindow(picwindow_name);
    while (1)
    {
        key = waitKey(30);
        capture >> frame;
        imshow(camera_name, frame);
        if (key == 27)
        {
            break;//ESC键退出
        }
        if (key == 's')
        {
            sprintf(picture_name, "pic%d.jpg", i++);//若保存在根目录,这样即可
            imwrite(picture_name, frame);
            imshow(picwindow_name, frame);
        }
    }
    return 0;
}
