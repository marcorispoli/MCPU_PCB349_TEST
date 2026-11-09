
#include "PCB.h"
#include "ConfigurationFiles.h"
#include "Log.h"
#include <thread>


bool PCB::activateMasTestCurrent(bool stat) {
    protocol.data_register.activate_mas_test_current = stat;
    return true;
}
bool PCB::getMasTestCurrentStatus(void) {
    return protocol.status_register.anodic_test_current_activated;
}

unsigned short PCB::getMasCalibPulses(void) {
    return protocol.status_register.mas_test_pulses;
}

unsigned short PCB::getMasCalibCurrent(void) {
    return protocol.status_register.anodic_test_current;
}




void PCB::runningLoop(void) {
    static bool commerr = false;
   
    // Test the communication status
    if (commerr != isCommunicationError()) {
        commerr = isCommunicationError();
        if (isCommunicationError()) {
            LogClass::logInFile("COMMUNICATION ERROR");
        }
        else {
            LogClass::logInFile("COMMUNICATION OK");
        }
    }


    //	Read System Status Register
    protocol.status_register.decodeSystemStatusRegister(readStatusRegister((unsigned char)ProtocolStructure::StatusRegister::register_index::SYSTEM_STATUS_IDX));
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    // Reads the mAs test register only if required
    if (protocol.status_register.anodic_test_current_activated) {
        protocol.status_register.decodeMasTestStatusRegister(readStatusRegister((unsigned char)ProtocolStructure::StatusRegister::register_index::MAS_TEST_STATUS_IDX));
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    

    // Write Data Registers here
    writeDataRegister(  (unsigned char)ProtocolStructure::DataRegister::register_index::SYSTEM_DATA_IDX, protocol.data_register.encodeSystemDataRegister());
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    return;


   
}



/// <summary>
/// 
/// </summary>
/// 
/// This function activate a One Shot alarm notifying the 
/// operator that the device has been reset. 
/// 
/// 
/// <param name=""></param>
void PCB::resetLoop(void) {

    LogClass::logInFile("RESET EVENT");
}

/// <summary>
/// This is the configuration loop routine executed at the beginning of the 
/// device connection, before to execute the runningLoop() routine.
/// 
/// 
/// </summary>
/// <param name=""></param>
/// <returns>true if the configuration success</returns>
bool PCB::configurationLoop(void) {
    
    LogClass::logInFile("CONFIGURATION EVENT");

    return true;
}
