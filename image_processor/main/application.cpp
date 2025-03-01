#include "application.hpp"

#include "filters/crop_filter_producer.hpp"
#include "filters/edge_detection_filter_producer.hpp"
#include "filters/fisheye_filter_producer.hpp"
#include "filters/gaussian_blur_filter.hpp"
#include "filters/gaussian_blur_filter_producer.hpp"
#include "filters/grayscale_filter_producer.hpp"
#include "filters/negative_filter_producer.hpp"
#include "filters/sharpening_filter_producer.hpp"

void Application::Config() {
    f_factory_.AddProducer("crop", new CropFilterProducer());
    f_factory_.AddProducer("gs", new GrayscaleFilterProducer());
    f_factory_.AddProducer("neg", new NegativeFilterProducer());
    f_factory_.AddProducer("sharp", new SharpeningFilterProducer());
    f_factory_.AddProducer("edge", new EdgeDetectionFilterProducer());
    f_factory_.AddProducer("blur", new GaussianBlurFilterProducer());
    f_factory_.AddProducer("fisheye", new FisheyeFilterProducer());
}

ErrorCode Application::Start(int argc, char** argv) {
    auto start_time = std::chrono::high_resolution_clock::now();

    try {
        if (ErrorCode result = cl_parser_.Parse(argc, argv, app_settings_); result != ErrorCode::SUCCESS) {
            return result;
        }

        for (const FilterSettings& filter_settings : app_settings_.filters_settings_) {
            FilterProducer* filter_producer = f_factory_.GetProducer(filter_settings.name_);
            if (!filter_producer) {
                std::cerr << "Filter with the given name does not exist.\n";
                return ErrorCode::INVALID_ARGUMENTS;
            }
            pipeline_.AddFilter(filter_producer->Produce(filter_settings));
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
        return ErrorCode::EXCEPTION;
    } catch (...) {
        std::cerr << "Unknown exception.\n";
        return ErrorCode::EXCEPTION;
    }

    auto cur_time = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(cur_time - start_time);

    std::cerr << "Time elapsed: " << dur.count() << "ms.\n";
    return ErrorCode::SUCCESS;
}