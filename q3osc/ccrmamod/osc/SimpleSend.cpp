/* 
    Simple example of sending an OSC message using oscpack.
*/
#include "test.h"
#include "/oscpack/osc/OscOutboundPacketStream.h"
#include "/oscpack/ip/UdpSocket.h"


#define ADDRESS "127.0.0.1"
#define PORT 7000

#define OUTPUT_BUFFER_SIZE 1024

int test()
{
    UdpTransmitSocket transmitSocket( IpEndpointName( ADDRESS, PORT ) );
    
    char buffer[OUTPUT_BUFFER_SIZE];
    osc::OutboundPacketStream p( buffer, OUTPUT_BUFFER_SIZE );
    
    p << osc::BeginBundleImmediate
        << osc::BeginMessage( "/test1" ) 
            << true << 23 << (float)3.1415 << "hello" << osc::EndMessage
        << osc::BeginMessage( "/test2" ) 
            << true << 24 << (float)10.8 << "world" << osc::EndMessage
        << osc::EndBundle;
    
    transmitSocket.Send( p.Data(), p.Size() );
}
