#include "application.hpp"

#include <chrono>

#include "filters/crop_filter_producer.hpp"
#include "filters/edge_detection_filter_producer.hpp"
#include "filters/fisheye_filter_producer.hpp"
#include "filters/gaussian_blur_filter_producer.hpp"
#include "filters/grayscale_filter_producer.hpp"
#include "filters/negative_filter_producer.hpp"
#include "filters/sharpening_filter_producer.hpp"

void Application::Config() {
    f_factory_.AddProducer("crop", std::make_unique<CropFilterProducer>());
    f_factory_.AddProducer("gs", std::make_unique<GrayscaleFilterProducer>());
    f_factory_.AddProducer("neg", std::make_unique<NegativeFilterProducer>());
    f_factory_.AddProducer("sharp", std::make_unique<SharpeningFilterProducer>());
    f_factory_.AddProducer("edge", std::make_unique<EdgeDetectionFilterProducer>());
    f_factory_.AddProducer("blur", std::make_unique<GaussianBlurFilterProducer>());
    f_factory_.AddProducer("fisheye", std::make_unique<FisheyeFilterProducer>());
}

void Application::Start(int argc, char** argv) {
    auto start_time = std::chrono::high_resolution_clock::now();

    try {

        cl_parser_.Parse(argc, argv, app_settings_);

        for (const FilterSettings& filter_settings : app_settings_.filters_settings_) {
            pipeline_.AddFilter(f_factory_.GetProducer(filter_settings.name_)->Produce(filter_settings));
        }

        BMP bmp;
        bmp.ReadFromFile(app_settings_.input_file_path_);
        Image image = bmp_image_converter_.GetImageFromBMP(bmp);

        pipeline_.ApplyPipeline(image);

        bmp = bmp_image_converter_.GetBMPFromImage(image, bmp.GetBMPHeader(), bmp.GetDIBHeader());
        bmp.WriteToFile(app_settings_.output_file_path_);
    } catch (std::invalid_argument& e) {
        std::cerr << "Invalid input: " << e.what() << "\n";
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    } catch (...) {
        std::cerr << "Unknown exception.\n";
    }

    auto cur_time = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(cur_time - start_time);

    std::cerr << "Time elapsed: " << dur.count() << "ms.\n";
}