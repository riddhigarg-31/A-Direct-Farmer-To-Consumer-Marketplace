#include "crow.h"
#include "market.h"

int main()
{
    crow::SimpleApp app;

    Market market;
    market.loadData();

    // API: Display all crops
    CROW_ROUTE(app, "/api/crops")([&market]()
    {
        auto crops = market.getAllCrops();

        crow::json::wvalue result;

        for (int i = 0; i < crops.size(); i++)
        {
            result[i]["cropID"] = crops[i].getcropID();
            result[i]["cropName"] = crops[i].getcropName();
            result[i]["category"] = crops[i].getcategory();
            result[i]["price"] = crops[i].getprice();
            result[i]["quantity"] = crops[i].getquantity();
            result[i]["expiry"] = crops[i].getexpiry();
            result[i]["farmerID"] = crops[i].getfarmerID();
        }

        crow::response res(result);
        res.add_header("Access-Control-Allow-Origin", "*");

        return res;
    });

    // API: Display crops according to expiry priority
    CROW_ROUTE(app, "/api/expiry-priority")([&market]()
    {
        auto crops = market.getExpiryPriorityCrops();

        crow::json::wvalue result;

        for (int i = 0; i < crops.size(); i++)
        {
            result[i]["cropID"] = crops[i].getcropID();
            result[i]["cropName"] = crops[i].getcropName();
            result[i]["category"] = crops[i].getcategory();
            result[i]["price"] = crops[i].getprice();
            result[i]["quantity"] = crops[i].getquantity();
            result[i]["expiry"] = crops[i].getexpiry();
            result[i]["farmerID"] = crops[i].getfarmerID();
        }

        crow::response res(result);
        res.add_header("Access-Control-Allow-Origin", "*");

        return res;
    });

    app.port(18080).multithreaded().run();
}
