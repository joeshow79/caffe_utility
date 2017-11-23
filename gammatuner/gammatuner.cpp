#include <iostream>
#include <vector>

#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc,char** argv){

	if ( argc != 2 )
	{
		cout<<"Usage: "<<argv[0]<<" Image_File_Name"<<endl;
		return -1;
	}

	Mat src=imread(argv[1]);

	float f[]={0.2,0.5,1.2,1.5};
	vector<float> gammaTable(f,f+4);

    // build look up table  
	vector<float>::iterator t;
    unsigned char lut[256][4];  
	
	int index;
	for(t=gammaTable.begin(),index=0;t!=gammaTable.end();t++,index++){
		//cout<<endl;
		for( int i = 0; i < 256; i++ )  
		{  
			lut[i][index] = saturate_cast<uchar>(pow((float)(i/255.0), *t) * 255.0f);  
		//	cout<<(int)lut[i][index]<<"\t";
		}  
		//cout<<endl;
	}
  
	for(t=gammaTable.begin(),index=0;t!=gammaTable.end();t++,index++){

		Mat dst = src.clone();  
		const int channels = dst.channels();  

		switch(channels)  
		{  
			case 1:  
				{  
						MatIterator_<uchar> it, end;  
						for( it = dst.begin<uchar>(), end = dst.end<uchar>(); it != end; it++ )  
							*it = lut[(*it)][index];  
  
					break;  
				}  
			case 3:   
				{  
	
					MatIterator_<Vec3b> it, end;  
					for( it = dst.begin<Vec3b>(), end = dst.end<Vec3b>(); it != end; it++ )  
					{  
						(*it)[0] = lut[((*it)[0])][index];  
						(*it)[1] = lut[((*it)[1])][index];  
						(*it)[2] = lut[((*it)[2])][index];  
					}  
	
					break;  
	
				}  
		}  
				
		stringstream buffer;
		buffer << *t;
		string output_name = buffer.str();
		
		output_name+=string(argv[1])+output_name+".png";
				    
		vector<int> compression_params;
		compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
		compression_params.push_back(9);
				
		try {
			imwrite(output_name, dst, compression_params);
		}
		catch (runtime_error& ex) {
			fprintf(stderr, "Exception converting image to PNG format: %s\n", ex.what());
			return 1;
		}
	}
}
