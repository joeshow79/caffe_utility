//------------------------------------------------------
// 内容：
//      　Paintの実現
//　　　　
//　　　　　　　　　　
//　　　　　　　　　　
//                   
//                                    2015.5.21
//                                    by zhou fan
// ------------------------------------------------------

#include <iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  

using namespace std;  

CvRect box;
bool drawing_box = false;
CvRect Eraser;
bool drawing_eraser = false;
int Eraser_Size = 5; 

void mouse_paint_callback(int event,
                          int x, 
                          int y, 
                          int flags, 
                          void* param);


void draw_box( IplImage* img, CvRect box)
{
    cvRectangle(img,
                cvPoint(box.x,box.y),
                cvPoint(box.x+box.width,box.y+box.height),
                cvScalar(0x00,0xff,0x00)    //Green
                );
}

void draw_Eraser( IplImage* img, CvRect Eraser)
{
    cvRectangle(img,
                cvPoint(Eraser.x - Eraser_Size,Eraser.y - Eraser_Size),
                cvPoint(Eraser.x + Eraser_Size,Eraser.y + Eraser_Size),
                cvScalar(0xff,0xff,0xff),    
                CV_FILLED
                );
}

void show_Eraser( IplImage* img, CvRect Eraser)
{
    cvRectangle(img,
                cvPoint(Eraser.x - Eraser_Size,Eraser.y - Eraser_Size),
                cvPoint(Eraser.x + Eraser_Size,Eraser.y + Eraser_Size),
                cvScalar(0x00,0x00,0x00),    
                CV_FILLED
                );
}

int main(int argc, char** argv)
{
    box = cvRect(-1,-1,0,0);
    Eraser = cvRect(-1,-1,0,0);

    IplImage* image = cvCreateImage(cvSize(500,500),
                                    IPL_DEPTH_8U,
                                    3);
    cvZero(image);
    cvAddS(image,cvScalarAll(255),image);
    IplImage* temp = cvCloneImage(image);

    cvNamedWindow("Paint");

    cvSetMouseCallback("Paint",
                       mouse_paint_callback,
                       (void*) image);

    while(1)
    {
        cvCopy(image,temp);
        if(drawing_box) draw_box(temp,box);
        if(drawing_eraser) show_Eraser(temp,Eraser);
        cvShowImage("Paint",temp);

        if(cvWaitKey(15) == 27) break;    //wait ESC key
    }

    return (int)0;
}


void mouse_paint_callback(int event,
                          int x, 
                          int y, 
                          int flags, 
                          void* param)
{
    IplImage* image = (IplImage*) param;

    switch(event)
    {
        case CV_EVENT_MOUSEMOVE: 
        {
            if(drawing_box)
            {
                //cout<< (flags & CV_EVENT_FLAG_SHIFTKEY) << n;
                if((flags & CV_EVENT_FLAG_SHIFTKEY) == CV_EVENT_FLAG_SHIFTKEY)
                {
                    if (box.x>box.y)
                    {           
                        box.width = x - box.x;
                        box.height= (y - box.y > 0)?abs(x - box.x):-abs(x - box.x);
                    }
                    else
                    {
                        box.width = (x - box.x > 0)?abs(y - box.y):-abs(y - box.y);
                        box.height= y - box.y;
                    }

                    //cout<< TURE << n;
                }
                else
                {
                    box.width = x - box.x;
                    box.height= y - box.y;
                }
            }

            if(drawing_eraser)
            {
               Eraser = cvRect(x,y,0,0);
               draw_Eraser(image,Eraser);
            }

        }
        break;

        case CV_EVENT_LBUTTONDOWN:
        {
            drawing_box = true;
            box = cvRect(x,y,0,0);
        }
        break;

        case CV_EVENT_RBUTTONDOWN:
        {
            drawing_eraser = true;
            Eraser = cvRect(x,y,0,0);
            draw_Eraser(image,Eraser);
        }
        break;

        case CV_EVENT_LBUTTONUP:
        {
            drawing_box = false;
            if(box.width<0)
            {
                box.x += box.width;
                box.width *= -1; 
            }
            if(box.height<0)
            {
                box.y += box.height;
                box.height *= -1; 
            }
            draw_box(image,box);
        }
        break;

        case CV_EVENT_RBUTTONUP:
        {
            drawing_eraser = false;
        }
        break;
    }

}
