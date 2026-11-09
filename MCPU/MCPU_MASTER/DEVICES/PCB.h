#pragma once
#include "CanDeviceProtocol.h"
#include "ConfigurationFiles.h"

#define CAN_ADDRESS 0x19
ref class PCB : public CanDeviceProtocol
{
public:

	
	/// <summary>
	/// This class implement the protocol data structure as described in the protocol specification.
	/// </summary>
	ref class ProtocolStructure {
	public:

		ref class StatusRegister {
		public:

			enum class register_index {
				SYSTEM_STATUS_IDX = 0,  
				MAS_TEST_STATUS_IDX,
				NUM_REGISTERS
			};



			static bool decodeSystemStatusRegister(Register^ sys) {
				if (sys == nullptr) return false;
				anodic_test_current_activated = (sys->d0 & 0x1) ? true : false;

				
				return true;
			}

			Register^ encodeSystemStatusRegister(void) {

				// Creates a register with all bytes set to 0
				CanDeviceProtocol::Register^ sys = gcnew CanDeviceProtocol::Register;

				// Byte 0 of the register
				sys->d0 = 0;
				if(anodic_test_current_activated) sys->d0 |= 1;
				
				
				// Returns the formatted register
				return sys;
			}

			static bool decodeMasTestStatusRegister(Register^ sys) {
				if (sys == nullptr) return false;
				anodic_test_current = (unsigned short)sys->d0 + (unsigned short)256 * sys->d1;
				mas_test_pulses = (unsigned short)sys->d2 + (unsigned short)256 * sys->d3;

				return true;
			}

			Register^ encodeMasTestStatusRegister(void) {

				// Creates a register with all bytes set to 0
				CanDeviceProtocol::Register^ sys = gcnew CanDeviceProtocol::Register;

				
				sys->d0 = anodic_test_current;
				sys->d1 = anodic_test_current>>8;

				sys->d2 = mas_test_pulses;
				sys->d3 = mas_test_pulses >> 8;


				// Returns the formatted register
				return sys;
			}

			
			// mAsmeter related parameters
			static bool			   anodic_test_current_activated = false;
			static unsigned short  anodic_test_current = 0;
			static unsigned short  mas_test_pulses = 0;


			
		};


		ref class DataRegister {
		public:

			enum class register_index {
				SYSTEM_DATA_IDX = 0, 
				NUM_REGISTERS = 0,
			};

			Register^ encodeSystemDataRegister(void) {

				// Creates a register with all bytes set to 0
				CanDeviceProtocol::Register^ sys = gcnew CanDeviceProtocol::Register;

				
				if(activate_mas_test_current) sys->d0 |= 0x1;

				
				return sys;
			}

			static bool decodeSystemDataRegister(Register^ sys) {
				if (sys == nullptr) return false;
				
				activate_mas_test_current = (sys->d0 & 0x1) ? true : false;


				return true;
			}

			static bool activate_mas_test_current = false;
		};

		ref class ParameterRegister {
		public:

			enum class register_index {
				
				NUM_REGISTERS = 0
			};

		};

		ref class Commands {
		public:
			enum class command_index {
				ABORT_COMMAND = 0, //!< Abort Command (mandatory as for device protocol)
				
			};

			/* EXAMPLE
			CanDeviceCommand^ encodeSetFormatCommand(unsigned char target_format_slot) {
				// if the index is out of range, the collimatin will be st to OPEN in the device
				if (target_format_slot >= NUM_COLLIMATION_SLOTS) target_format_slot = 0;
				return gcnew CanDeviceCommand((unsigned char)command_index::SET_FORMAT, target_format_slot, 0, 0, 0);
			}*/


		};

		static StatusRegister status_register;
		static DataRegister data_register;
		static ParameterRegister parameter_register;
		static Commands command;
	};

	
	/// <summary>
	/// PCB303 Class constructor.
	/// 
	/// The construction initializes several internal variables.
	/// The constructor call the base class setting the address of the controlled device.
	/// 
	/// As soon as the base class is initialized, the communication process starts
	/// and the device is initialized with configurationLoop() routine.
	/// \ingroup PCB303_Interface
	/// </summary>
	public: PCB() : CanDeviceProtocol(CAN_ADDRESS, L"PCB")
	{
		
	}
	static PCB^ device = gcnew PCB();

	/// \ingroup PCB335_Internal
	///@{
	/// 
	protected: 	
		void resetLoop(void) override;//!< This is the Base class resetLoop override function
		void runningLoop(void) override;//!< This is the Base Class override function to handle the normal operation workflow 
		bool configurationLoop(void) override;//!< This is the Base Class override function to handle the device configuration
		
	
	private:	
		
		

	///@}
	
	

	/// \ingroup PCB_Internal
	///@{
	private: 
		static ProtocolStructure protocol; //!< This is the structure with the Status register info
		


	///@}

public:
	/// \ingroup PCB_Interface
	///@{
	static bool activateMasTestCurrent(bool stat);
	static bool getMasTestCurrentStatus(void);
	static unsigned short getMasCalibPulses(void);
	static unsigned short getMasCalibCurrent(void);
	
	///@}
};


