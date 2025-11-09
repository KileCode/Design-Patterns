#include <iostream>
#include "ComputerFacade.h"

using namespace std;

int main() {
    cout << "\n========================================" << endl;
    cout << "  FACADE DESIGN PATTERN DEMONSTRATION" << endl;
    cout << "      Computer Startup Example" << endl;
    cout << "========================================\n" << endl;
    
    // Create the facade object
    ComputerFacade computer;
    
    // Simple interface: Just call start() instead of managing all subsystems
    // Without facade, the client would need to:
    //   1. Create CPU, Memory, HardDrive, and BIOS objects
    //   2. Call BIOS POST and hardware initialization
    //   3. Perform memory tests
    //   4. Initialize CPU
    //   5. Spin up hard drive and seek boot sector
    //   6. Load boot data into memory
    //   7. Jump CPU to boot address
    //   8. Execute boot instructions
    // The facade handles all of this complexity!
    
    computer.start();
    
    cout << "\n[Press Enter to shutdown...]" << endl;
    cin.get();
    
    computer.shutdown();
    
    cout << "\n========================================" << endl;
    cout << "  DEMONSTRATION OF SUBSYSTEM ACCESS" << endl;
    cout << "========================================\n" << endl;
    
    // The facade pattern doesn't prevent direct subsystem access
    // Clients can still access subsystems if they need more control
    cout << "Demonstrating that subsystems are still accessible:\n" << endl;
    cout << "CPU Status: " << computer.getCPU()->getStatus() << endl;
    cout << "Memory Size: " << computer.getMemory()->getSize() << "GB" << endl;
    cout << "OS Name: " << computer.getHardDrive()->getOSName() << endl;
    cout << "BIOS Version: " << computer.getBIOS()->getVersion() << endl;
    
    cout << "\nThis demonstrates the key principle from the document:" << endl;
    cout << "\"The facade should be implemented in such a way that it" << endl;
    cout << "doesn't prevent applications from using subsystem classes" << endl;
    cout << "if they need to.\"\n" << endl;
    
    return 0;
}