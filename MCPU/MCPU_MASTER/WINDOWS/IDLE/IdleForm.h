#pragma once
#include <Windows.h>


/// \addtogroup OPERMODEDOC
/// <div style="page-break-after: always;"></div>
/// 
/// # Idle Panel
/// 





using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


/// <summary>
/// \ingroup IDLEIMPL
/// 
/// This is the Idle Panel mode implementing module
/// 
/// </summary>
public ref class IdleForm : public System::Windows::Forms::Form
{

#define WINMSG_TIMER WM_USER + 1 //!< This is the Window message used to handle the form timer
#define WINMSG_OPEN WINMSG_TIMER + 1 //!< This is the Window message used to handle a Open window request
#define WINMSG_CLOSE WINMSG_OPEN + 1 //!< This is the Window message used to handle a Close window request


public:
	System::Timers::Timer^ idleTimer; //!< This is the form Timer used to schedule the Idle Status activities


public:
	void idleStatusManagement(void);	//!< This is the Idel Status activity handler
	void initIdleStatus(void);			//!< Initializes the form at the Open event

	void open(void);					//!< Open window request method
	void close(void);					//!< Close window request method
private: System::Windows::Forms::Panel^ mAsPanel;
public:




private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::Label^ mAsFreqValue;




public:

public:
	bool open_status;					//!< Current Open/Close Status


private:HWND window;
private: System::Windows::Forms::Label^ labelDate;

private: System::Windows::Forms::Label^ labelTime;
private: System::Windows::Forms::PictureBox^ QuitButton;
private: System::Windows::Forms::Label^ BoardTestLabel;
private: System::Windows::Forms::Label^ mAsFreqLabel;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Label^ CalibtrationCurrentValue;

private: System::Windows::Forms::Label^ AnodicCurrentLabel;
private: System::Windows::Forms::Label^ AnodicCurrentValue;
public: System::Windows::Forms::NumericUpDown^ ManualAnodicCalibrationValue;
private:



private: System::Windows::Forms::Button^ ManualAnodicCalibrationButton;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Button^ AutoCalibrationButton;
private: System::Windows::Forms::Label^ MonitorOnOff;
private: System::Windows::Forms::Button^ MonitorButton;


private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ CalibrationTimeValue;
private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::Label^ CalibrationPulsesValue;
private: System::Windows::Forms::Label^ VrefOnOff;
private: System::Windows::Forms::Button^ VrefButton;
private: System::Windows::Forms::Panel^ panel1;
private: System::Windows::Forms::Button^ StartIntegratorButton;








public: System::Windows::Forms::NumericUpDown^ IntegrationMas;
private:




private:

public:


private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::Label^ integratedTimeValue;

private: System::Windows::Forms::Label^ label19;
private: System::Windows::Forms::Label^ label20;
private: System::Windows::Forms::Label^ integratedMasValue;

public: System::Windows::Forms::NumericUpDown^ IntegrationTmo;
private: System::Windows::Forms::Label^ labelTimeout;
public:

public:
private: System::Windows::Forms::Label^ label7;
private:

private: System::Windows::Forms::Panel^ mainPanel;


private:void formInitialization(void);


public:
	IdleForm(void)
	{
		InitializeComponent();
		window = static_cast<HWND>(Handle.ToPointer());
		formInitialization();

	}

protected:
	/// <summary>
	/// Clean up any resources being used.
	/// </summary>
	~IdleForm()
	{
		if (components)
		{
			delete components;
		}
	}




protected:
private:
	/// <summary>
	/// Required designer variable.
	/// </summary>
	System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
	/// <summary>
	/// Required method for Designer support - do not modify
	/// the contents of this method with the code editor.
	/// </summary>
	void InitializeComponent(void)
	{
        this->labelDate = (gcnew System::Windows::Forms::Label());
        this->labelTime = (gcnew System::Windows::Forms::Label());
        this->mainPanel = (gcnew System::Windows::Forms::Panel());
        this->panel1 = (gcnew System::Windows::Forms::Panel());
        this->labelTimeout = (gcnew System::Windows::Forms::Label());
        this->label7 = (gcnew System::Windows::Forms::Label());
        this->IntegrationTmo = (gcnew System::Windows::Forms::NumericUpDown());
        this->StartIntegratorButton = (gcnew System::Windows::Forms::Button());
        this->IntegrationMas = (gcnew System::Windows::Forms::NumericUpDown());
        this->label17 = (gcnew System::Windows::Forms::Label());
        this->integratedTimeValue = (gcnew System::Windows::Forms::Label());
        this->label19 = (gcnew System::Windows::Forms::Label());
        this->label20 = (gcnew System::Windows::Forms::Label());
        this->integratedMasValue = (gcnew System::Windows::Forms::Label());
        this->BoardTestLabel = (gcnew System::Windows::Forms::Label());
        this->mAsPanel = (gcnew System::Windows::Forms::Panel());
        this->VrefOnOff = (gcnew System::Windows::Forms::Label());
        this->VrefButton = (gcnew System::Windows::Forms::Button());
        this->MonitorOnOff = (gcnew System::Windows::Forms::Label());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->CalibrationPulsesValue = (gcnew System::Windows::Forms::Label());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->CalibrationTimeValue = (gcnew System::Windows::Forms::Label());
        this->MonitorButton = (gcnew System::Windows::Forms::Button());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->AutoCalibrationButton = (gcnew System::Windows::Forms::Button());
        this->ManualAnodicCalibrationValue = (gcnew System::Windows::Forms::NumericUpDown());
        this->ManualAnodicCalibrationButton = (gcnew System::Windows::Forms::Button());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->CalibtrationCurrentValue = (gcnew System::Windows::Forms::Label());
        this->AnodicCurrentLabel = (gcnew System::Windows::Forms::Label());
        this->AnodicCurrentValue = (gcnew System::Windows::Forms::Label());
        this->mAsFreqLabel = (gcnew System::Windows::Forms::Label());
        this->label6 = (gcnew System::Windows::Forms::Label());
        this->mAsFreqValue = (gcnew System::Windows::Forms::Label());
        this->QuitButton = (gcnew System::Windows::Forms::PictureBox());
        this->mainPanel->SuspendLayout();
        this->panel1->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IntegrationTmo))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IntegrationMas))->BeginInit();
        this->mAsPanel->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ManualAnodicCalibrationValue))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->QuitButton))->BeginInit();
        this->SuspendLayout();
        // 
        // labelDate
        // 
        this->labelDate->AutoSize = true;
        this->labelDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelDate->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(156)), static_cast<System::Int32>(static_cast<System::Byte>(149)),
            static_cast<System::Int32>(static_cast<System::Byte>(149)));
        this->labelDate->Location = System::Drawing::Point(12, 964);
        this->labelDate->Name = L"labelDate";
        this->labelDate->Size = System::Drawing::Size(100, 24);
        this->labelDate->TabIndex = 7;
        this->labelDate->Text = L"27/10/2023";
        // 
        // labelTime
        // 
        this->labelTime->AutoSize = true;
        this->labelTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelTime->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(156)), static_cast<System::Int32>(static_cast<System::Byte>(149)),
            static_cast<System::Int32>(static_cast<System::Byte>(149)));
        this->labelTime->Location = System::Drawing::Point(12, 988);
        this->labelTime->Name = L"labelTime";
        this->labelTime->Size = System::Drawing::Size(88, 24);
        this->labelTime->TabIndex = 9;
        this->labelTime->Text = L"10:35 PM";
        // 
        // mainPanel
        // 
        this->mainPanel->Controls->Add(this->panel1);
        this->mainPanel->Controls->Add(this->BoardTestLabel);
        this->mainPanel->Controls->Add(this->mAsPanel);
        this->mainPanel->Location = System::Drawing::Point(0, 0);
        this->mainPanel->Name = L"mainPanel";
        this->mainPanel->Size = System::Drawing::Size(599, 800);
        this->mainPanel->TabIndex = 14;
        // 
        // panel1
        // 
        this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
        this->panel1->Controls->Add(this->labelTimeout);
        this->panel1->Controls->Add(this->label7);
        this->panel1->Controls->Add(this->IntegrationTmo);
        this->panel1->Controls->Add(this->StartIntegratorButton);
        this->panel1->Controls->Add(this->IntegrationMas);
        this->panel1->Controls->Add(this->label17);
        this->panel1->Controls->Add(this->integratedTimeValue);
        this->panel1->Controls->Add(this->label19);
        this->panel1->Controls->Add(this->label20);
        this->panel1->Controls->Add(this->integratedMasValue);
        this->panel1->Location = System::Drawing::Point(276, 69);
        this->panel1->Name = L"panel1";
        this->panel1->Size = System::Drawing::Size(254, 279);
        this->panel1->TabIndex = 15;
        // 
        // labelTimeout
        // 
        this->labelTimeout->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->labelTimeout->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
            static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->labelTimeout->Location = System::Drawing::Point(164, 46);
        this->labelTimeout->Name = L"labelTimeout";
        this->labelTimeout->Size = System::Drawing::Size(85, 24);
        this->labelTimeout->TabIndex = 27;
        this->labelTimeout->Text = L"Tmo (ms)";
        this->labelTimeout->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
        // 
        // label7
        // 
        this->label7->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
            static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->label7->Location = System::Drawing::Point(7, 46);
        this->label7->Name = L"label7";
        this->label7->Size = System::Drawing::Size(79, 24);
        this->label7->TabIndex = 26;
        this->label7->Text = L"mAs";
        this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
        // 
        // IntegrationTmo
        // 
        this->IntegrationTmo->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->IntegrationTmo->Location = System::Drawing::Point(163, 73);
        this->IntegrationTmo->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000, 0, 0, 0 });
        this->IntegrationTmo->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
        this->IntegrationTmo->Name = L"IntegrationTmo";
        this->IntegrationTmo->Size = System::Drawing::Size(79, 32);
        this->IntegrationTmo->TabIndex = 25;
        this->IntegrationTmo->TabStop = false;
        this->IntegrationTmo->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
        this->IntegrationTmo->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
        // 
        // StartIntegratorButton
        // 
        this->StartIntegratorButton->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->StartIntegratorButton->Location = System::Drawing::Point(7, 187);
        this->StartIntegratorButton->Name = L"StartIntegratorButton";
        this->StartIntegratorButton->Size = System::Drawing::Size(235, 58);
        this->StartIntegratorButton->TabIndex = 24;
        this->StartIntegratorButton->Text = L"START INTEGRATION";
        this->StartIntegratorButton->UseVisualStyleBackColor = true;
        this->StartIntegratorButton->Click += gcnew System::EventHandler(this, &IdleForm::StartIntegratorButton_Click);
        // 
        // IntegrationMas
        // 
        this->IntegrationMas->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->IntegrationMas->Location = System::Drawing::Point(7, 73);
        this->IntegrationMas->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 640, 0, 0, 0 });
        this->IntegrationMas->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
        this->IntegrationMas->Name = L"IntegrationMas";
        this->IntegrationMas->Size = System::Drawing::Size(79, 32);
        this->IntegrationMas->TabIndex = 20;
        this->IntegrationMas->TabStop = false;
        this->IntegrationMas->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
        this->IntegrationMas->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
        // 
        // label17
        // 
        this->label17->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label17->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
            static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->label17->Location = System::Drawing::Point(3, 139);
        this->label17->Name = L"label17";
        this->label17->Size = System::Drawing::Size(161, 24);
        this->label17->TabIndex = 16;
        this->label17->Text = L"Intergrated Time (ms)";
        this->label17->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
        // 
        // integratedTimeValue
        // 
        this->integratedTimeValue->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->integratedTimeValue->ForeColor = System::Drawing::Color::White;
        this->integratedTimeValue->Location = System::Drawing::Point(170, 139);
        this->integratedTimeValue->Name = L"integratedTimeValue";
        this->integratedTimeValue->Size = System::Drawing::Size(72, 24);
        this->integratedTimeValue->TabIndex = 15;
        this->integratedTimeValue->Text = L"----";
        this->integratedTimeValue->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
        // 
        // label19
        // 
        this->label19->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label19->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
            static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->label19->Location = System::Drawing::Point(3, 115);
        this->label19->Name = L"label19";
        this->label19->Size = System::Drawing::Size(161, 24);
        this->label19->TabIndex = 14;
        this->label19->Text = L"Integrated mAs";
        this->label19->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
        // 
        // label20
        // 
        this->label20->BackColor = System::Drawing::Color::LemonChiffon;
        this->label20->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label20->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)));
        this->label20->Location = System::Drawing::Point(-1, 0);
        this->label20->Name = L"label20";
        this->label20->Size = System::Drawing::Size(254, 29);
        this->label20->TabIndex = 13;
        this->label20->Text = L"mAs-integrator";
        this->label20->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // integratedMasValue
        // 
        this->integratedMasValue->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->integratedMasValue->ForeColor = System::Drawing::Color::White;
        this->integratedMasValue->Location = System::Drawing::Point(170, 115);
        this->integratedMasValue->Name = L"integratedMasValue";
        this->integratedMasValue->Size = System::Drawing::Size(72, 24);
        this->integratedMasValue->TabIndex = 12;
        this->integratedMasValue->Text = L"----";
        this->integratedMasValue->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
        // 
        // BoardTestLabel
        // 
        this->BoardTestLabel->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->BoardTestLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)));
        this->BoardTestLabel->Location = System::Drawing::Point(20, 9);
        this->BoardTestLabel->Name = L"BoardTestLabel";
        this->BoardTestLabel->Size = System::Drawing::Size(555, 40);
        this->BoardTestLabel->TabIndex = 14;
        this->BoardTestLabel->Text = L"Board Test Panel";
        this->BoardTestLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // mAsPanel
        // 
        this->mAsPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
        this->mAsPanel->Controls->Add(this->VrefOnOff);
        this->mAsPanel->Controls->Add(this->VrefButton);
        this->mAsPanel->Controls->Add(this->MonitorOnOff);
        this->mAsPanel->Controls->Add(this->label5);
        this->mAsPanel->Controls->Add(this->CalibrationPulsesValue);
        this->mAsPanel->Controls->Add(this->label2);
        this->mAsPanel->Controls->Add(this->CalibrationTimeValue);
        this->mAsPanel->Controls->Add(this->MonitorButton);
        this->mAsPanel->Controls->Add(this->label4);
        this->mAsPanel->Controls->Add(this->label3);
        this->mAsPanel->Controls->Add(this->AutoCalibrationButton);
        this->mAsPanel->Controls->Add(this->ManualAnodicCalibrationValue);
        this->mAsPanel->Controls->Add(this->ManualAnodicCalibrationButton);
        this->mAsPanel->Controls->Add(this->label1);
        this->mAsPanel->Controls->Add(this->CalibtrationCurrentValue);
        this->mAsPanel->Controls->Add(this->AnodicCurrentLabel);
        this->mAsPanel->Controls->Add(this->AnodicCurrentValue);
        this->mAsPanel->Controls->Add(this->mAsFreqLabel);
        this->mAsPanel->Controls->Add(this->label6);
        this->mAsPanel->Controls->Add(this->mAsFreqValue);
        this->mAsPanel->Location = System::Drawing::Point(16, 68);
        this->mAsPanel->Name = L"mAsPanel";
        this->mAsPanel->Size = System::Drawing::Size(254, 391);
        this->mAsPanel->TabIndex = 14;
        // 
        // VrefOnOff
        // 
        this->VrefOnOff->BackColor = System::Drawing::Color::Maroon;
        this->VrefOnOff->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->VrefOnOff->ForeColor = System::Drawing::Color::White;
        this->VrefOnOff->Location = System::Drawing::Point(203, 74);
        this->VrefOnOff->Name = L"VrefOnOff";
        this->VrefOnOff->Size = System::Drawing::Size(40, 32);
        this->VrefOnOff->TabIndex = 30;
        this->VrefOnOff->Text = L"OFF";
        this->VrefOnOff->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // VrefButton
        // 
        this->VrefButton->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->VrefButton->Location = System::Drawing::Point(7, 74);
        this->VrefButton->Name = L"VrefButton";
        this->VrefButton->Size = System::Drawing::Size(189, 32);
        this->VrefButton->TabIndex = 29;
        this->VrefButton->Text = L"VREF";
        this->VrefButton->UseVisualStyleBackColor = true;
        this->VrefButton->Click += gcnew System::EventHandler(this, &IdleForm::VrefButton_Click);
        // 
        // MonitorOnOff
        // 
        this->MonitorOnOff->BackColor = System::Drawing::Color::Maroon;
        this->MonitorOnOff->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->MonitorOnOff->ForeColor = System::Drawing::Color::White;
        this->MonitorOnOff->Location = System::Drawing::Point(203, 36);
        this->MonitorOnOff->Name = L"MonitorOnOff";
        this->MonitorOnOff->Size = System::Drawing::Size(40, 32);
        this->MonitorOnOff->TabIndex = 25;
        this->MonitorOnOff->Text = L"OFF";
        this->MonitorOnOff->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // label5
        // 
        this->label5->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label5->ForeColor = System::Drawing::Color::Aqua;
        this->label5->Location = System::Drawing::Point(3, 212);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(193, 24);
        this->label5->TabIndex = 28;
        this->label5->Text = L"Calibration Pulses";
        this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
        // 
        // CalibrationPulsesValue
        // 
        this->CalibrationPulsesValue->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->CalibrationPulsesValue->ForeColor = System::Drawing::Color::White;
        this->CalibrationPulsesValue->Location = System::Drawing::Point(171, 212);
        this->CalibrationPulsesValue->Name = L"CalibrationPulsesValue";
        this->CalibrationPulsesValue->Size = System::Drawing::Size(72, 24);
        this->CalibrationPulsesValue->TabIndex = 27;
        this->CalibrationPulsesValue->Text = L"----";
        this->CalibrationPulsesValue->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
        // 
        // label2
        // 
        this->label2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label2->ForeColor = System::Drawing::Color::Aqua;
        this->label2->Location = System::Drawing::Point(3, 188);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(193, 24);
        this->label2->TabIndex = 26;
        this->label2->Text = L"Calibration Time (ms)";
        this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
        // 
        // CalibrationTimeValue
        // 
        this->CalibrationTimeValue->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->CalibrationTimeValue->ForeColor = System::Drawing::Color::White;
        this->CalibrationTimeValue->Location = System::Drawing::Point(171, 188);
        this->CalibrationTimeValue->Name = L"CalibrationTimeValue";
        this->CalibrationTimeValue->Size = System::Drawing::Size(72, 24);
        this->CalibrationTimeValue->TabIndex = 25;
        this->CalibrationTimeValue->Text = L"----";
        this->CalibrationTimeValue->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
        // 
        // MonitorButton
        // 
        this->MonitorButton->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->MonitorButton->Location = System::Drawing::Point(7, 36);
        this->MonitorButton->Name = L"MonitorButton";
        this->MonitorButton->Size = System::Drawing::Size(189, 32);
        this->MonitorButton->TabIndex = 24;
        this->MonitorButton->Text = L"MONITOR";
        this->MonitorButton->UseVisualStyleBackColor = true;
        this->MonitorButton->Click += gcnew System::EventHandler(this, &IdleForm::MonitorButton_Click);
        // 
        // label4
        // 
        this->label4->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label4->ForeColor = System::Drawing::Color::Aqua;
        this->label4->Location = System::Drawing::Point(5, 317);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(237, 24);
        this->label4->TabIndex = 23;
        this->label4->Text = L"Internal mA Calibration";
        this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
        // 
        // label3
        // 
        this->label3->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label3->ForeColor = System::Drawing::Color::Aqua;
        this->label3->Location = System::Drawing::Point(5, 255);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(237, 24);
        this->label3->TabIndex = 22;
        this->label3->Text = L"Real mA Calibration";
        this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
        // 
        // AutoCalibrationButton
        // 
        this->AutoCalibrationButton->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->AutoCalibrationButton->Location = System::Drawing::Point(7, 344);
        this->AutoCalibrationButton->Name = L"AutoCalibrationButton";
        this->AutoCalibrationButton->Size = System::Drawing::Size(235, 32);
        this->AutoCalibrationButton->TabIndex = 21;
        this->AutoCalibrationButton->Text = L"AUTO CALIBRATION";
        this->AutoCalibrationButton->UseVisualStyleBackColor = true;
        this->AutoCalibrationButton->Click += gcnew System::EventHandler(this, &IdleForm::AutoCalibrationButton_Click);
        // 
        // ManualAnodicCalibrationValue
        // 
        this->ManualAnodicCalibrationValue->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
        this->ManualAnodicCalibrationValue->Location = System::Drawing::Point(163, 282);
        this->ManualAnodicCalibrationValue->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 200, 0, 0, 0 });
        this->ManualAnodicCalibrationValue->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
        this->ManualAnodicCalibrationValue->Name = L"ManualAnodicCalibrationValue";
        this->ManualAnodicCalibrationValue->Size = System::Drawing::Size(79, 32);
        this->ManualAnodicCalibrationValue->TabIndex = 20;
        this->ManualAnodicCalibrationValue->TabStop = false;
        this->ManualAnodicCalibrationValue->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
        this->ManualAnodicCalibrationValue->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
        // 
        // ManualAnodicCalibrationButton
        // 
        this->ManualAnodicCalibrationButton->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->ManualAnodicCalibrationButton->Location = System::Drawing::Point(7, 282);
        this->ManualAnodicCalibrationButton->Name = L"ManualAnodicCalibrationButton";
        this->ManualAnodicCalibrationButton->Size = System::Drawing::Size(150, 32);
        this->ManualAnodicCalibrationButton->TabIndex = 19;
        this->ManualAnodicCalibrationButton->Text = L"MANUAL CAL.";
        this->ManualAnodicCalibrationButton->UseVisualStyleBackColor = true;
        this->ManualAnodicCalibrationButton->Click += gcnew System::EventHandler(this, &IdleForm::ManualAnodicCalibrationButton_Click);
        // 
        // label1
        // 
        this->label1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label1->ForeColor = System::Drawing::Color::Aqua;
        this->label1->Location = System::Drawing::Point(3, 164);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(193, 24);
        this->label1->TabIndex = 18;
        this->label1->Text = L"Calibration Current (mA)";
        this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
        // 
        // CalibtrationCurrentValue
        // 
        this->CalibtrationCurrentValue->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->CalibtrationCurrentValue->ForeColor = System::Drawing::Color::White;
        this->CalibtrationCurrentValue->Location = System::Drawing::Point(170, 164);
        this->CalibtrationCurrentValue->Name = L"CalibtrationCurrentValue";
        this->CalibtrationCurrentValue->Size = System::Drawing::Size(72, 24);
        this->CalibtrationCurrentValue->TabIndex = 17;
        this->CalibtrationCurrentValue->Text = L"----";
        this->CalibtrationCurrentValue->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
        // 
        // AnodicCurrentLabel
        // 
        this->AnodicCurrentLabel->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->AnodicCurrentLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
            static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->AnodicCurrentLabel->Location = System::Drawing::Point(3, 140);
        this->AnodicCurrentLabel->Name = L"AnodicCurrentLabel";
        this->AnodicCurrentLabel->Size = System::Drawing::Size(161, 24);
        this->AnodicCurrentLabel->TabIndex = 16;
        this->AnodicCurrentLabel->Text = L"Anodic Current (mA)";
        this->AnodicCurrentLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
        // 
        // AnodicCurrentValue
        // 
        this->AnodicCurrentValue->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->AnodicCurrentValue->ForeColor = System::Drawing::Color::White;
        this->AnodicCurrentValue->Location = System::Drawing::Point(170, 140);
        this->AnodicCurrentValue->Name = L"AnodicCurrentValue";
        this->AnodicCurrentValue->Size = System::Drawing::Size(72, 24);
        this->AnodicCurrentValue->TabIndex = 15;
        this->AnodicCurrentValue->Text = L"----";
        this->AnodicCurrentValue->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
        // 
        // mAsFreqLabel
        // 
        this->mAsFreqLabel->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->mAsFreqLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
            static_cast<System::Int32>(static_cast<System::Byte>(128)));
        this->mAsFreqLabel->Location = System::Drawing::Point(3, 116);
        this->mAsFreqLabel->Name = L"mAsFreqLabel";
        this->mAsFreqLabel->Size = System::Drawing::Size(161, 24);
        this->mAsFreqLabel->TabIndex = 14;
        this->mAsFreqLabel->Text = L"Frequency (pls/s)";
        this->mAsFreqLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
        // 
        // label6
        // 
        this->label6->BackColor = System::Drawing::Color::LemonChiffon;
        this->label6->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
            static_cast<System::Int32>(static_cast<System::Byte>(0)));
        this->label6->Location = System::Drawing::Point(-1, 0);
        this->label6->Name = L"label6";
        this->label6->Size = System::Drawing::Size(254, 29);
        this->label6->TabIndex = 13;
        this->label6->Text = L"mAs-monitor";
        this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // mAsFreqValue
        // 
        this->mAsFreqValue->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->mAsFreqValue->ForeColor = System::Drawing::Color::White;
        this->mAsFreqValue->Location = System::Drawing::Point(170, 116);
        this->mAsFreqValue->Name = L"mAsFreqValue";
        this->mAsFreqValue->Size = System::Drawing::Size(72, 24);
        this->mAsFreqValue->TabIndex = 12;
        this->mAsFreqValue->Text = L"----";
        this->mAsFreqValue->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
        // 
        // QuitButton
        // 
        this->QuitButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
        this->QuitButton->Location = System::Drawing::Point(214, 812);
        this->QuitButton->Name = L"QuitButton";
        this->QuitButton->Size = System::Drawing::Size(200, 200);
        this->QuitButton->TabIndex = 15;
        this->QuitButton->TabStop = false;
        this->QuitButton->Click += gcnew System::EventHandler(this, &IdleForm::QuitButton_Click);
        // 
        // IdleForm
        // 
        this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
            static_cast<System::Int32>(static_cast<System::Byte>(60)));
        this->ClientSize = System::Drawing::Size(600, 1024);
        this->ControlBox = false;
        this->Controls->Add(this->QuitButton);
        this->Controls->Add(this->mainPanel);
        this->Controls->Add(this->labelDate);
        this->Controls->Add(this->labelTime);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        this->Name = L"IdleForm";
        this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
        this->mainPanel->ResumeLayout(false);
        this->panel1->ResumeLayout(false);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IntegrationTmo))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IntegrationMas))->EndInit();
        this->mAsPanel->ResumeLayout(false);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ManualAnodicCalibrationValue))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->QuitButton))->EndInit();
        this->ResumeLayout(false);
        this->PerformLayout();

    }
#pragma endregion

protected:  virtual void WndProc(System::Windows::Forms::Message% m) override;

private: System::Void onIdleTimeout(Object^ source, System::Timers::ElapsedEventArgs^ e)
{
	SendMessageA(window, WINMSG_TIMER, 0, 0);
}



	   // Pulsante di chiusura pannello
private: System::Void QuitButton_Click(System::Object^ sender, System::EventArgs^ e) {
	exit(0);
}


private: System::Void AutoCalibrationButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ManualAnodicCalibrationButton_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void MonitorButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void VrefButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void StartIntegratorButton_Click(System::Object^ sender, System::EventArgs^ e);




};

