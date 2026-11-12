
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
bool PCB::getMasAutoCalibrationStatus(void) {
    return protocol.status_register.auto_calibration_activated;
}

bool PCB::getMasManualCalibrationStatus(void) {
    return protocol.status_register.manual_calibration_activated;
}

unsigned short PCB::getMasTestPulses(void) {
    return protocol.status_register.mas_test_pulses;
}

unsigned short PCB::getMasTestCurrent(void) {
    return protocol.status_register.anodic_test_current;
}


unsigned char PCB::getMasCalibCurrent(void) {
    return protocol.parameter_register.calibrated_anodic_current;
}

unsigned char PCB::getMasCalib10msTime(void) {
    return protocol.parameter_register.calibrated_integration_time_10ms;
}

unsigned short PCB::getMasCalibPulses(void) {
    return protocol.parameter_register.calibrated_pulses;
}

bool PCB::ExecuteAutoCalbration(void) {
    if (protocol.status_register.auto_calibration_activated) return false;
    if (!device->commandNoWaitCompletion(protocol.command.encodeActivateAutocalibration(), 30)) return false;

    return true;
}

bool PCB::ExecuteManualCalibration(int ma) {
    if (ma > 255) return false;
    if (protocol.status_register.manual_calibration_activated) return false;
    if (protocol.status_register.auto_calibration_activated) return false;
    if (!device->commandNoWaitCompletion(protocol.command.encodeActivateManualcalibration(ma), 30)) return false;

    return true;
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

    // Read The Calibration Register
    protocol.parameter_register.decodeMasParamRegister(readParamRegister((unsigned char)ProtocolStructure::ParameterRegister::register_index::MAS_PARAM_IDX));


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
    
    // Read The Calibration Register
    protocol.parameter_register.decodeMasParamRegister(readParamRegister((unsigned char)ProtocolStructure::ParameterRegister::register_index::MAS_PARAM_IDX));

    return true;
}
