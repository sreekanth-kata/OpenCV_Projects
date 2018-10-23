#include "core.hpp"



int main(int argc, char** argv)
{
	
	//CGenericObject l_cGenericObject = CGenericObject(CGenericObject::OBJECT_TYPE_HAND);	
	//std::cout << l_cGenericObject.getObjTypeName() << std::endl;
	


	return true;
}




void showSample(std::string name)
{
	cv::Mat image;
	image = cv::imread(name, 1);

	if (!image.data)
	{
		printf("No image data \n");
		return;
	}

	cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Display Image", image);

	cv::waitKey(0);
}