#include "application.hpp"

int main(int argc, char* argv[]) {
    Application app;
    app.Config();

    if (ErrorCode result = app.Start(argc, argv); result != ErrorCode::SUCCESS) {
        return static_cast<int>(result);
    }

    return 0;
}