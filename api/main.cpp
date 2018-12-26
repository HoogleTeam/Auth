#include <memory>
#include <cstdlib>
#include <restbed>
#include "auth_functions.h"

int main(const int, const char**){
  
  //Resources
  
  //SignIn
  auto signIn = make_shared< Resource >();
  signIn->set_path("/api/signIn");
  signIn->set_method_handler("GET",sign_in_handler);
  
  //SignOut
  auto signOut = make_shared< Resource >();
  signOut->set_path("/api/signOut");
  signOut->set_method_handler("GET",sign_out_handler);
  
  //SignUp
  auto signUp = make_shared< Resource >();
  signUp->set_path("/api/signUp");
  signUp->set_method_handler("GET", sign_up_handler);
  
  //TokenValidate
  auto tokenValidate = make_shared< Resource >();
  tokenValidate->set_path("/api/validateToken");
  tokenValidate->set_method_handler("GET", token_validate);
  
  
  //Add settings
  auto settings = make_shared< Settings >( );
  settings->set_port( 1984 );
  settings->set_default_header( "Connection", "close" );

  
  //Define the service
  Service service;
  //Publish our resources
  service.publish( signIn );
  service.publish( signOut );
  service.publish( signUp );
  service.publish( tokenValidate );
  
  //Start the service
  service.start( settings );

  return EXIT_SUCCESS;
}
