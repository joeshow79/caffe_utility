/*
 *
 * Author:jason jiao
 *
 * History:
 * 2017-11-21: initial version
 * 
 * Reference:
 * http://blog.csdn.net/zhoufan900428/article/details/45890053
 *
 *
*/

#include <iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
#include <libgen.h>
#include <dirent.h>  
#include <sys/stat.h>  
#include <unistd.h>  
#include <stdio.h>

using namespace std;  
using namespace cv;

CvRect box;
CvRect Masker;
CvRect Eraser;
bool drawing_eraser = false;
bool drawing_mask = false;
int op_size = 1; 
double alpha=0.5;
CvScalar mask_color(0xff,0xff,0xff);
CvScalar background_color(0x0,0x0,0x0);

IplImage* orig=NULL;
IplImage* mask=NULL;
IplImage* processed_mask=NULL;

void mouse_paint_callback(int event, int x, int y, int flags, void* param);


void draw_box( IplImage* img, CvRect box)
{
    cvRectangle(img,
                cvPoint(box.x,box.y),
                cvPoint(box.x+box.width,box.y+box.height),
                cvScalar(0xff,0xff,0xff),CV_FILLED
                );
	
	if(processed_mask){
		for(int x=box.x;x<=box.x+box.width;x++){
			for(int y=box.y;y<=box.y+box.height;y++){
				if(x>0 && x<=img->width && y>0 && y<=img->height){
					cvSet2D(processed_mask,y,x,mask_color);
				}
			}
		}
	}
}

void draw_mask( IplImage* img, CvRect Mask)
{
	CvScalar sample=cvGet2D(img,Mask.y,Mask.x);

	//TBD: Check  if the mask is set as (255,255,255) at the x,y, if yes, do nothing
	
	{
		int x;
		int y;
		cvRectangle(img, cvPoint(Mask.x - op_size,Mask.y - op_size), cvPoint(Mask.x + op_size,Mask.y + op_size), cvScalar(0xff,0xff,0xff),    CV_FILLED);
		//cvCircle(img, cvPoint(Mask.x ,Mask.y) ,op_size,cvScalar(0xff,0xff,0xff));
		if(processed_mask){
			for(int i=-op_size;i<=op_size;i++){
				for(int j=-op_size;j<=op_size;j++){
					x=Mask.x+i;
					y=Mask.y+j;
					if(x>0 && x<=img->width && y>0 && y<=img->height){
						cvSet2D(processed_mask,y,x,mask_color);
					}
				}
			}
		}
	}
}

void show_mask( IplImage* img, CvRect Mask)
{
    cvRectangle(img,
                cvPoint(Mask.x - op_size,Mask.y - op_size),
                cvPoint(Mask.x + op_size,Mask.y + op_size),
                cvScalar(0x00,0x00,0xff),    
                CV_FILLED
                );
}

void draw_eraser( IplImage* img, CvRect Eraser)
{
    cvRectangle(img,
                cvPoint(Eraser.x - op_size,Eraser.y - op_size),
                cvPoint(Eraser.x + op_size,Eraser.y + op_size),
                cvScalar(0x0,0x0,0x0),    
                CV_FILLED
                );
		int x;
		int y;
		//cvCircle(img, cvPoint(Eraser.x ,Eraser.y) ,op_size,cvScalar(0x0,0x0,0x0));
		if(processed_mask){
			for(int i=-op_size;i<=op_size;i++){
				for(int j=-op_size;j<=op_size;j++){
					x=Eraser.x+i;
					y=Eraser.y+j;
					if(x>0 && x<=img->width && y>0 && y<=img->height){
						cvSet2D(processed_mask,y,x,background_color);
					}
				}
			}
		}
}

void show_eraser( IplImage* img, CvRect Eraser)
{
    cvRectangle(img,
                cvPoint(Eraser.x - op_size,Eraser.y - op_size),
                cvPoint(Eraser.x + op_size,Eraser.y + op_size),
                cvScalar(0x80,0x80,0x80),    
                CV_FILLED
                );
}

void mouse_paint_callback(int event, int x, int y, int flags, void* param)
{
	//cout<<x<<":"<<y<<endl;

    IplImage* image = (IplImage*) param;

    switch(event)
    {
        case CV_EVENT_MOUSEMOVE: 
        {
            if(drawing_mask)
            {
                /*if((flags & CV_EVENT_FLAG_SHIFTKEY) == CV_EVENT_FLAG_SHIFTKEY)
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
                }
                else
                {
                    box.width = x - box.x;
                    box.height= y - box.y;
                }*/
                if((flags & CV_EVENT_FLAG_SHIFTKEY) == CV_EVENT_FLAG_SHIFTKEY) {
					Masker = cvRect(x,y,0,0);
					draw_mask(image,Masker);
				}
            }

            if(drawing_eraser)
            {
               if((flags & CV_EVENT_FLAG_SHIFTKEY) == CV_EVENT_FLAG_SHIFTKEY) {
					Eraser = cvRect(x,y,0,0);
					draw_eraser(image,Eraser);
			   }
            }

        }
        break;
        case CV_EVENT_LBUTTONDOWN:
        {
               if((flags & CV_EVENT_FLAG_SHIFTKEY) == CV_EVENT_FLAG_SHIFTKEY) {
					drawing_mask = true;
					Masker = cvRect(x,y,0,0);
					draw_mask(image,Masker);
					box = cvRect(x,y,0,0);
			   }
        }
        break;

        case CV_EVENT_RBUTTONDOWN:
        {
               if((flags & CV_EVENT_FLAG_SHIFTKEY) == CV_EVENT_FLAG_SHIFTKEY) {
					drawing_eraser = true;
					Eraser = cvRect(x,y,0,0);
					draw_eraser(image,Eraser);
			   }
        }
        break;

        case CV_EVENT_LBUTTONUP:
        {
            drawing_mask = false;
/*            if(box.width<0)
            {
                box.x += box.width;
                box.width *= -1; 
            }
            if(box.height<0)
            {
                box.y += box.height;
                box.height *= -1; 
            }
            if((flags & CV_EVENT_FLAG_SHIFTKEY) == CV_EVENT_FLAG_SHIFTKEY){
				draw_box(image,box);
			}*/
        }
        break;

        case CV_EVENT_RBUTTONUP:
        {
            drawing_eraser = false;
        }
        break;
    }

}

int usage(int argc){
	if ( argc != 2 )
	{
		printf("usage: masktuner <Image_Dir_Path>\n");
		return -1;
	}
	return 0;
}

int main(int argc, char** argv)
{
	int result=usage(argc);
	if(result!=0){
		return result;
	}

    Masker = cvRect(-1,-1,0,0);
    Eraser = cvRect(-1,-1,0,0);

	//Iterator the data dir
	char* dir_name=argv[1];
    if( NULL == dir_name )  
    {  
        cout<< "dir_name is null ! "<<endl;  
        return -1;  
    }  
  
    // check if dir_name is a valid dir  
    struct stat s;  
    lstat( dir_name , &s );  
    if( ! S_ISDIR( s.st_mode ) )  
    {  
        return -1;  
    }  
      
    struct dirent * file_name;    // return value for readdir()  
    DIR * dir;                   // return value for opendir()  
    dir = opendir( dir_name );  
    if( NULL == dir )  
    {  
        cout<<"Can not open dir"<<dir_name<<endl;  
        return -1;  
    }  
      
    /* read all the files in the dir ~ */  
    while( ( file_name = readdir(dir) ) != NULL )  
    {  
        // get rid of . and ..  
        if( strcmp( file_name->d_name , "." ) == 0 ||   
            strcmp( file_name->d_name , "..") == 0    )  
            continue;  

		string file_str(file_name->d_name);
		//TBD: hard code for the list of jpg files only
		if(file_str.compare(file_str.size()-3,3,"jpg")==0){

			string orig_image_name=string(dir_name)+"/"+file_str;
			string mask_image_name=string(dir_name)+"/"+file_str.replace(file_str.size()-3,3,"png");

			cout<<"processing ..."<<endl;
			cout<<orig_image_name<<endl;
			cout<<mask_image_name<<endl;

			//processed image file name
			char cmask_image_name[1024];
			strncpy(cmask_image_name,mask_image_name.c_str(),sizeof(cmask_image_name));
			cmask_image_name[sizeof(cmask_image_name)-1]=0;
			string output_name=string(basename(cmask_image_name));
			output_name=string(dir_name)+"/"+"p_"+output_name;
			//cout<<output_name<<endl;

			orig=cvLoadImage(orig_image_name.c_str(),1);
			mask=cvLoadImage(mask_image_name.c_str(),1);


			if (orig==NULL)
			{
				printf("No orig picture, skip to next one \n");
				continue;
			}

			if (mask==NULL)
			{
				printf("No mask picture, skip to next one \n");
				continue;
			}

			if(orig->width!=mask->width || orig->height!=mask->height) {
				printf("Size of original and mask pictures are not matched. Skip to next one.\n");
				continue;
			}

			IplImage* image = cvCreateImage(cvSize(orig->width,orig->height), IPL_DEPTH_8U, 3);
			processed_mask = cvCreateImage(cvSize(orig->width,orig->height), IPL_DEPTH_8U, 3);
			processed_mask = cvCloneImage(mask);

			cvZero(image);
			//cvAddS(image,cvScalarAll(255),image);
			cvAddWeighted(orig,alpha,mask,1.0-alpha,0.0,image);
			IplImage* temp = cvCloneImage(image);

			cvNamedWindow("MaskTuner");

			cvSetMouseCallback("MaskTuner", mouse_paint_callback, (void*) image);

			while(1)
			{
				cvCopy(image,temp);
				if(drawing_eraser) show_eraser(temp,Eraser);
				if(drawing_mask) {
					show_mask(temp,Masker);
					draw_box(temp,box);
				}
				cvShowImage("MaskTuner",temp);
		
				if(cvWaitKey(15) == 27) return 1;    //wait ESC key
				if(cvWaitKey(30) == 13){//wait Return key
					cvSaveImage(output_name.c_str(),processed_mask);	
					break;
				}
		
			}
			cvDestroyWindow("MaskTuner");
		}
    }  

    return (int)0;
}

