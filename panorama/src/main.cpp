

#include <opencv2/highgui.hpp>					// ��� �������� ������
#include <opencv2/stitching.hpp>				// ��� ������ �����������
#include <opencv2/imgproc.hpp>					// ������� ��������� �����������


#include <iostream>
#include <vector>
#include <string>

#include "serviceFunction.h"


//=======================================================================================
//
//		Description: ������ ���������� �������� ���� ����������� � �������������� OpenCV
//		Auth:	Vadim Yarmushov
//		Date: 17/03/21
//		Ver: 0.0.1
//		
//=======================================================================================


using namespace serviceFunction;

int main(int argc, char* argv[])
{
  

	std::cout << "\n";
    std::cout << "\nInitialization system OpenCV..."<< std::endl;
	std::cout << "Description: application for composite two images in the one panorama" << std::endl;
	std::cout << "Author: Vadim Yarmushov" << std::endl;
	std::cout << "Date: 17/03/2021" << std::endl;
	std::cout << "ver: 0.0.1 " << std::endl;
	int flags = cv::IMREAD_UNCHANGED;		// ��������� ����������� ��� ����, ���� ���� ����� �����, �� ��������



	bool useGPU = false;								// ������������ �� ����������� �����������
	cv::Stitcher::Mode mode = cv::Stitcher::PANORAMA;	// ������� ����� ��� �������� �������, ���������� ���������� �������� �� �����.
//	cv::Stitcher::Mode mode = cv::Stitcher::SCANS;		// ������� ����� ����������� ������
	std::vector<cv::Mat> images;						// ��������� �����������
	std::string result_name = "result.jpg";

	// ���� �� ����� ����� ������� �����������
	if (argc == 1)
	{
		print_instruction();	// ������� ����������
		return -1;
	}

	cv::Mat panorama;		// ����� ������ ���������� ��������
//	cv::Mat temp_image;		// ����� ������ ��������� �����������
	int num_images = argc -1 ;	//	���������� ����������� ������
//	images.reserve(num_images);

	// �������� ����������� � ������
	for (int img_index = 1; img_index <= (num_images); ++img_index) 
	{
	
		cv::Mat temp_image = cv::imread(argv[img_index]);			// cv::Mat temp_image ����� ������ ��������� �����������
		images.push_back(temp_image);

		
	}
	
	


	// �������� ����������� �����������
	cv::Ptr<cv::Stitcher> stitcher = cv::Stitcher::create(mode);		// ��������� �������� �������
	cv::Stitcher::Status status = stitcher->stitch(images, panorama);	// ������� �������, ��������� � ������� ������� ��������� �������� ����������� � �������������� �����������
		

	if (status != cv::Stitcher::OK)
	{
		std::cout << "Can't stitch images, error code = " << status << std::endl;
		return -1;
	}

	cv::imwrite(result_name, panorama);
   
    
	std::cout << "\n";
	std::cout << "\nEnd Prog" << std::endl;
	std::cout << "\n";
	system("pause");
	return 0;
}