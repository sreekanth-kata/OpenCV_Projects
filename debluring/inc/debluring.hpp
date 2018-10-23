#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>

#include "iostream"

class CImageLoader
{
public:
	CImageLoader(std::string f_firstImageFilename_s)
	{
		m_firstImage = cv::imread(f_firstImageFilename_s, 1);
	}

	bool copyROIImagePart();

	cv::Mat getROIImage();

	cv::Rect2d getROI();

private:	
	bool showImage();

	bool showRoiImage();

	bool selectROI();
	
	cv::Mat m_roiImage;
	cv::Rect2d m_roi;
	cv::Mat m_firstImage;
};

cv::Rect2d CImageLoader::getROI()
{
	assert(m_roi.size().width >= 0 && m_roi.size().height >= 0 && "Invalid ROI size");

	return m_roi;
}

cv::Mat CImageLoader::getROIImage()
{
	assert(m_roiImage.size().width>=0 && m_roiImage.size().height>=0 && "Zero size image");

	return m_roiImage;
}

bool CImageLoader::copyROIImagePart()
{
	
	bool l_success_b = selectROI();
	if (l_success_b)
		l_success_b &= showRoiImage();
	cv::waitKey(0);

	return l_success_b;
}

bool CImageLoader::showImage()
{
	bool l_success_b = true;

	std::string l_roiWinName = "MainImage";
	cv::namedWindow(l_roiWinName, cv::WINDOW_AUTOSIZE);
	cv::imshow(l_roiWinName, m_firstImage);

	if (cv::getWindowProperty(l_roiWinName, cv::WND_PROP_AUTOSIZE) == -1)
		l_success_b = false;

	return l_success_b;
}

bool CImageLoader::showRoiImage()
{
	bool l_success_b = true;

	m_roiImage = m_firstImage(m_roi);

	std::string l_roiWinName = "RoiImage";
	cv::namedWindow(l_roiWinName, cv::WINDOW_AUTOSIZE);
	cv::imshow(l_roiWinName, m_roiImage);

	if (cv::getWindowProperty(l_roiWinName, cv::WND_PROP_AUTOSIZE) == -1)
		l_success_b = false;

	return l_success_b;
}

bool CImageLoader::selectROI()
{
	bool l_success_b = false;

	m_roi = cv::selectROI(m_firstImage);

	if (m_roi.width != 0.0f && m_roi.height != 0.0f)
		l_success_b = true;
	else
		std::cout << "Warning! ROI is still unset" << std::endl;

	return l_success_b;
}