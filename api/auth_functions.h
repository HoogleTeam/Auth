#ifndef PLAYER_H
#define PLAYER_H

void signIn_handler(const shared_ptr<Session> session) {
  const auto request = session->get_request( );

  int content_length = request->get_header( "Content-Length", 0 );

  session->fetch( content_length, [ ]( const shared_ptr< Session > session, const Bytes & body )
  {
      fprintf( stdout, "%.*s\n", ( int ) body.size( ), body.data( ) );
      
      session->close( OK, "Hello, World!", { { "Content-Length", "13" } } );
  });
}
#endif
