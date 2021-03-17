

#include <opencv2/highgui.hpp>					// для загрузки файлов
#include <opencv2/stitching.hpp>				// для сшивки изображений
#include <opencv2/imgproc.hpp>					// функции обработки изображений


#include <iostream>
#include <vector>
#include <string>

#include "serviceFunction.h"


//=======================================================================================
//
//		Description: Проект занимается склейкой двух изображений с использованием OpenCV
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
	int flags = cv::IMREAD_UNCHANGED;		// загрузить изображения как есть, если есть альфа канал, то оставить



	bool useGPU = false;								// использовать ли графический акселератор
	cv::Stitcher::Mode mode = cv::Stitcher::PANORAMA;	// выберем режим для создания панорам, проецирует полученную панораму на сферу.
//	cv::Stitcher::Mode mode = cv::Stitcher::SCANS;		// выберем режим составления сканов
	std::vector<cv::Mat> images;						// хранилище изображений
	std::string result_name = "result.jpg";

	// если не ввели имена входных изображений
	if (argc == 1)
	{
		print_instruction();	// выведем инструкцию
		return -1;
	}

	cv::Mat panorama;		// здесь храним полученную панораму
//	cv::Mat temp_image;		// здесь храним временное изображение
	int num_images = argc -1 ;	//	количество загруженных файлов
//	images.reserve(num_images);

	// загрузим изображения в вектор
	for (int img_index = 1; img_index <= (num_images); ++img_index) 
	{
	
		cv::Mat temp_image = cv::imread(argv[img_index]);			// cv::Mat temp_image здесь храним временное изображение
		images.push_back(temp_image);

		
	}
	
	


	// создадим соединенное изображение
	cv::Ptr<cv::Stitcher> stitcher = cv::Stitcher::create(mode);		// установим параметр склейки
	cv::Stitcher::Status status = stitcher->stitch(images, panorama);	// процесс склейки, передадим в функцию склейки хранилище исходных изображений и результирующее изображение
		

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