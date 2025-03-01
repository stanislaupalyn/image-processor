#include "application.hpp"

int main(int argc, char* argv[]) {
    Application app;
    app.Config();
    app.Start(argc, argv);

    return 0;
}