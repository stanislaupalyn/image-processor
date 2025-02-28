#include "application.hpp"

void Application::Config() {
    f_factory_.AddProducer("crop", ProduceCropFilter);
    f_factory_.AddProducer("gs", ProduceGrayscaleFilter);
    f_factory_.AddProducer("neg", ProduceNegativeFilter);
    f_factory_.AddProducer("sharp", ProduceSharpeningFilter);
    f_factory_.AddProducer("edge", ProduceEdgeDetectionFilter);
    f_factory_.AddProducer("blur", ProduceGaussianBlurFilter);
    f_factory_.AddProducer("fisheye", ProduceFisheyeFilter);
}

ErrorCode Application::Start(int argc, char** argv) {
    auto start_time = std::chrono::high_resolution_clock::now();

    try {
        ErrorCode result = cl_parser_.Parse(argc, argv, app_settings_);
        if (result != ErrorCode::SUCCESS) {
            return result;
        }

        for (const FilterSettings& filter_settings : app_settings_.filters_settings_) {
            FilterProducer filter_producer = f_factory_.GetProducer(filter_settings.name_);
            if (!filter_producer) {
                std::cerr << "Filter with the given name does not exist.\n";
                return ErrorCode::INVALID_ARGUMENTS;
            }
            ErrorCode error{};
            Filter* filter = filter_producer(filter_settings, error);

            if (!filter) {
                return error;
            }
            pipeline_.AddFilter(filter);
        }

        BMP bmp;
        bmp.ReadFromFile(app_settings_.input_file_path_);
        Image image = bmp_image_converter_.GetImageFromBMP(bmp);

        pipeline_.ApplyPipeline(image);

        bmp = bmp_image_converter_.GetBMPFromImage(image, bmp.GetBMPHeader(), bmp.GetDIBHeader());
        bmp.WriteToFile(app_settings_.output_file_path_);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    } catch (...) {
        std::cerr << "Unknown exception.\n";
    }

    auto cur_time = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(cur_time - start_time);

    std::cerr << "Time elapsed: " << dur.count() << "ms.\n";
    return ErrorCode::SUCCESS;
}