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
				MAS_INTEGRATOR_STATUS_IDX, //!< This register provides the last integration result
				NUM_REGISTERS
			};


			static bool decodeSystemStatusRegister(Register^ sys) {
				if (sys == nullptr) return false;
				mas_monitor_activated = (sys->d0 & 0x1) ? true : false;
				mas_vref_activated = (sys->d0 & 0x2) ? true : false;
				mas_auto_calibration_activated = (sys->d0 & 0x4) ? true : false;
				mas_manual_calibration_activated = (sys->d0 & 0x8) ? true : false;
				
				return true;
			}

			Register^ encodeSystemStatusRegister(void) {

				// Creates a register with all bytes set to 0
				CanDeviceProtocol::Register^ sys = gcnew CanDeviceProtocol::Register;

				// Byte 0 of the register
				sys->d0 = 0;
				if(mas_monitor_activated) sys->d0 |= 1;
				if (mas_vref_activated) sys->d0 |= 2;
				if (mas_auto_calibration_activated) sys->d0 |= 4;
				if (mas_manual_calibration_activated) sys->d0 |= 8;

				// Returns the formatted register
				return sys;
			}

			static bool decodeMasTestStatusRegister(Register^ sys) {
				if (sys == nullptr) return false;
				mas_anodic_current = (unsigned short)sys->d0 + (unsigned short)256 * sys->d1;
				mas_counts = (unsigned short)sys->d2 + (unsigned short)256 * sys->d3;

				return true;
			}

			Register^ encodeMasTestStatusRegister(void) {

				// Creates a register with all bytes set to 0
				CanDeviceProtocol::Register^ sys = gcnew CanDeviceProtocol::Register;

				
				sys->d0 = mas_anodic_current;
				sys->d1 = mas_anodic_current >>8;

				sys->d2 = mas_counts;
				sys->d3 = mas_counts >> 8;


				// Returns the formatted register
				return sys;
			}

			static bool decodeMasIntegratorStatusRegister(Register^ sys) {
				if (sys == nullptr) return false;
				dmas_integrated = (unsigned short)sys->d0 + (unsigned short)256 * sys->d1;
				mas_integrated_time = (unsigned short)sys->d2 + (unsigned short)256 * sys->d3;

				return true;
			}

			Register^ encodeMasIntegratorStatusRegister(void) {

				// Creates a register with all bytes set to 0
				CanDeviceProtocol::Register^ sys = gcnew CanDeviceProtocol::Register;


				sys->d0 = dmas_integrated;
				sys->d1 = dmas_integrated >> 8;

				sys->d2 = mas_integrated_time;
				sys->d3 = mas_integrated_time >> 8;


				// Returns the formatted register
				return sys;
			}

			

			// mAsmeter related parameters
			static bool			   mas_monitor_activated = false;
			static bool			   mas_vref_activated = false;
			static bool			   mas_auto_calibration_activated = false;
			static bool			   mas_manual_calibration_activated = false;

			static unsigned short  mas_anodic_current = 0;
			static unsigned short  mas_counts = 0;

			static unsigned short  dmas_integrated = 0;
			static unsigned short  mas_integrated_time = 0;



			
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

				
				if(mas_internal_monitor) sys->d0 |= 0x1;
				if(mas_monitor_with_vref) sys->d0 |= 0x2;

				
				return sys;
			}

			static bool decodeSystemDataRegister(Register^ sys) {
				if (sys == nullptr) return false;
				
				mas_internal_monitor = (sys->d0 & 0x1) ? true : false;
				mas_monitor_with_vref = (sys->d0 & 0x2) ? true : false;

				return true;
			}

			static bool mas_internal_monitor = false;
			static bool mas_monitor_with_vref = false;

		};

		ref class ParameterRegister {
		public:

			enum class register_index {
				
				MAS_PARAM_IDX = 0,
			};


			Register^ encodeMasParamRegister(void) {

				// Creates a register with all bytes set to 0
				CanDeviceProtocol::Register^ sys = gcnew CanDeviceProtocol::Register;

				sys->d0 = calibrated_pulses;
				sys->d1 = calibrated_pulses >> 8;
				sys->d2 = calibrated_anodic_current;
				sys->d3 = calibrated_integration_time_10ms;
				
				return sys;
			}

			static bool decodeMasParamRegister(Register^ sys) {
				if (sys == nullptr) return false;

				calibrated_pulses = (unsigned short)sys->d0 + (unsigned short)256 * sys->d1;
				calibrated_anodic_current = sys->d2;
				calibrated_integration_time_10ms = sys->d3;
				return true;
			}

			static unsigned short calibrated_pulses;
			static unsigned char  calibrated_integration_time_10ms;
			static unsigned char  calibrated_anodic_current;

		};

		/// <summary>
		/// This is the Prototcol command implementation section.
		/// </summary>
		/// 
		/// The \ref command_index enumeration defines the implemented command codes.
		/// 
		/// Every command is provided with the encoding function to fill the \ref CanDeviceCommand structure
		/// with the data to execute the related command.
		/// 
		/// \**Usage Example**\
		/// 
		/// + device->commandNoWaitCompletion(protocol.command.encode_xxx(parameters), 30));
		/// + device->commandWaitCompletion(protocol.command.encode_xxx(parameters), 30));
		/// 
		/// + The first call version sends the command without waiting the command execution event.
		/// + The second call version sends the command waiting for the command completion. 
		/// 
		/// Note: The secnd version can only be used by a different thread than the this device thread.
		/// 		
		ref class Commands {
		public:
			enum class command_index {
				ABORT_COMMAND = 0,			//!< Abort Command (mandatory as for device protocol)
				CMD_MAS_AUTO_CALIBRATION,	//!< Automatic Masmeter calibration 
				CMD_MAS_MANUAL_CALIBRATION,	//!< Manual Masmeter calibration 
				CMD_MAS_START_INTEGRATOR,   //!< Execute an Integration session
			};

			/// <summary>
			/// This is the Command encoding function to build the Auto Calibration Command execution
			/// </summary>
			/// <param name=""></param>
			/// <returns></returns>
			CanDeviceCommand^ encodeActivateAutocalibration(void) {
				return gcnew CanDeviceCommand((unsigned char)command_index::CMD_MAS_AUTO_CALIBRATION, 0, 0, 0, 0);
			}

			CanDeviceCommand^ encodeActivateManualcalibration(unsigned char val) {
				return gcnew CanDeviceCommand((unsigned char)command_index::CMD_MAS_MANUAL_CALIBRATION,(BYTE) val, 0, 0, 0);
			}

			CanDeviceCommand^ encodeActivateIntegration(unsigned short dmas, unsigned short timeout_ms) {
				BYTE mas_l = (dmas & 0xff);
				BYTE mas_h = ((dmas >> 8) & 0xff);
				BYTE t_l = (timeout_ms & 0xff);
				BYTE t_h = ((timeout_ms >> 8) & 0xff);

				return gcnew CanDeviceCommand((unsigned char)command_index::CMD_MAS_START_INTEGRATOR, mas_l, mas_h, t_l, t_h);
			}

			
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
	static bool setMasMonitor(bool stat, bool use_vref);
	static bool getMasMonitorStatus(void);
	static bool getMasVrefStatus(void);
	static bool getMasAutoCalibrationStatus(void);
	static bool getMasManualCalibrationStatus(void);

	static unsigned short getMasMonitorCounts(void);
	static unsigned short getMasMonitorCurrent(void);
	static unsigned short getDMasIntegrator(void);
	static unsigned short getMasIntegratorTime(void);


	static unsigned char  getMasCalibCurrent(void);
	static unsigned char  getMasCalib10msTime(void);
	static unsigned short getMasCalibPulses(void);

	// Command execution
	static bool			  ExecuteAutoCalbration(void);
	static bool			  ExecuteManualCalibration(int ma);
	static bool			  ExecuteIntegratorCommand(int dmas, int tmo_ms);
	///@}
};


