//A helpful library for creating a REST API
#include "crow.h"
#include <iostream>

using namespace std;

//A function for defining routes
void addRoute(string route,string function){
  CROW_ROUTE(app, route)([](){
    function();
  });
}

int main() {
  crow::SimpleApp app;
   
}
