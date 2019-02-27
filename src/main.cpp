#include <base64.hpp>
#include <filter.hpp>
#include <main.hpp>

#include <crow.h>

#include <memory>

int main(int argc, char ** argv) {

    std::vector<std::string> arguments(argv + 1, argv + argc);

    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
        .methods("POST"_method)
        ([](const crow::request& req) {
            auto body = req.body;
            crow::response res;
            res.add_header("Content-type", "image/png");
            res.body = Core::Filter::gaussian(body);
            return res;
        });

    app.port(18080).run();

    return 0;
}