#include "colorspace.hpp"


int main(int argc, char **argv)
{
	cv::Mat l_imageOutdoor, l_imageIndoor;

	l_imageOutdoor = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
	l_imageIndoor = cv::imread(argv[2], CV_LOAD_IMAGE_COLOR);
	// argv[3] is the output.pgm
	cv::Mat l_imageDepth = cv::imread(argv[4], CV_LOAD_IMAGE_ANYDEPTH);
	cv::Mat l_imageResultDepth = cv::Mat(l_imageDepth.size(), CV_16UC1);
		
	cv::Mat l_imageGray = cv::Mat::zeros(l_imageIndoor.size(), CV_8UC1);	
	cv::cvtColor(l_imageIndoor, l_imageGray, CV_RGB2GRAY);		

	cv::Mat l_magePGM = cv::Mat(l_imageGray.size(), CV_8UC2);

	std::cout << "depth type: " << l_imageDepth.type() << std::endl; // prints 2 == CV_16UC1
	std::cout << "CV_8UC2 type: " << CV_8UC2 << std::endl;
	std::cout << "CV_16UC1 type: " << CV_16UC1 << std::endl;
	
	
	// write a 16 bit binary P5 PGM image
	std::ofstream stream(argv[3], std::ios_base::out |std::ios_base::binary);
	ushort* l_imageDataPGM = new ushort[l_imageDepth.cols*l_imageDepth.rows];
	stream << "P5" << " " << l_imageDepth.cols << " " << l_imageDepth.rows << " " << 65535U << "\n";
	uchar* ptr = l_imageDepth.data;
	ushort data;
	for (int i = 0; i < 2 * l_imageDepth.cols * l_imageDepth.rows; ++i, ptr++)
	{
		l_imageResultDepth.data[i] = *ptr;
		if (i % 2 == 0)
		{
			memcpy(&data, ptr, 2);
			l_imageDataPGM[i / 2] = ((data << 8) | (data >> 8));
			// stream.write(reinterpret_cast<char*>(ptr), sizeof(uchar));
			// stream.write(reinterpret_cast<char*>(ptr+1), sizeof(uchar));
			// OR
			// stream.write(reinterpret_cast<char*>(ptr), sizeof(ushort));
		}
	}
	stream.write(reinterpret_cast<char*>(l_imageDataPGM), 2 * l_imageDepth.cols * l_imageDepth.rows);
	stream.close();


	// write a 16 bit binary P5 PGM image from a Grayscale PNG
	ushort* l_imageDataPNG = new ushort[l_imageGray.cols*l_imageGray.rows];
	std::ofstream streampng(argv[5], std::ios_base::out | std::ios_base::binary);
	streampng << "P5" << " " << l_imageGray.cols << " " << l_imageGray.rows << " " << 65535U << "\n";
	uchar* ptrpng = l_imageGray.data;
	uchar a[2];
	ushort datapng;
	for (int i = 0; i < l_imageGray.cols * l_imageGray.rows; ++i, ptrpng++)
	{
		a[0] = 0;
		a[1] = *ptrpng;		
		memcpy(&datapng, a, 2);
		// l_imageDataPNG[i] = datapng;
		l_imageDataPNG[i] = ((datapng << 8) | (datapng >> 8));
	}
	streampng.write(reinterpret_cast<char*>(l_imageDataPNG), 2 * l_imageGray.cols * l_imageGray.rows);
	streampng.close();


	/*for (int col = 0; col < l_imageGray.cols; ++col) {for (int row = 0; row < l_imageGray.rows; ++row) {l_imageResult.at<uchar>(row, col) = l_imageGray.at<uchar>(row, col);}}*/

	std::string win1_name = "Window1";
	cv::namedWindow(win1_name);
	cv::imshow(win1_name, l_imageResultDepth);
	cv::imwrite("C:\\Users\\dawudmaxx\\Entwirkler\\Code\\cvt\\colorspace\\data\\depth-output.png", l_imageResultDepth);
	cv::waitKey(0);
	cv::destroyWindow(win1_name);

	return 1;
}