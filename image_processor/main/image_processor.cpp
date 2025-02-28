#include "application.hpp"

int main(int argc, char* argv[]) {
    Application app;
    app.Config();

    ErrorCode result = app.Start(argc, argv);
    if (result != ErrorCode::SUCCESS) {
        return static_cast<int>(result);
    }

    return 0;
}