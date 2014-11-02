#include <iostream>
#include <SerialStream.h>

#define PORT "/dev/ttyACM0"

using namespace LibSerial;
using namespace std;

SerialStream ardu;

int main(int argc, char const *argv[])
{
    if (argc < 2){
        cout << argv[0] << "  <biit>\n";
        return 1;
    }

    ardu.Open("/dev/ttyACM0");
    ardu.SetBaudRate(SerialStreamBuf::BAUD_9600);
    ardu.SetCharSize(SerialStreamBuf::CHAR_SIZE_8);
    ardu.SetParity(SerialStreamBuf::PARITY_NONE);
    ardu.SetNumOfStopBits(1);
    ardu.SetFlowControl(SerialStreamBuf::FLOW_CONTROL_NONE);

    usleep(3500000);

    int res;
    ardu << argv[1][0];
    ardu >> res;
    
    cout << res;
    
    return 0;
}