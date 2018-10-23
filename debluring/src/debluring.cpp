#include "debluring.hpp"


int main(int argc, char** argv)
{
	CImageLoader l_cImageLoader = CImageLoader(argv[1]);
	
	bool l_success_b = l_cImageLoader.copyROIImagePart();
	if (l_success_b) std::cout << "ROI copied successfully" << std::endl;	
	
	cv::Mat l_roiImage = l_cImageLoader.getROIImage();
	
	return 1;
}