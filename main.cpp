#include <iostream>

#include "user.h"
#include "platform.h"
//#include "event.h"

using namespace std;

int main()
{

    User user1("example", "password");

    user1.displayInfo();

    Platform platform;

    platform.run();

    return 0;
}
