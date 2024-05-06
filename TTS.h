#pragma once
#include <map>
#include <string>
#include <sstream>

namespace textToSpeech {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for TTS
	/// </summary>
	///
	public ref class TTS : public System::Windows::Forms::Form
	{
	public:
		TTS(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TTS()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Label^ HEADER;
	private: System::Windows::Forms::TextBox^ textToBeVoiced;

	private: System::Windows::Forms::Button^ VoiceButton;

	private: System::Windows::Forms::Button^ StopButton;
	private: System::Speech::Synthesis::SpeechSynthesizer voice_synthesizer;
	private: System::Windows::Forms::Label^ Output;
	private: System::Windows::Forms::Button^ TranslatorButton;
	private: System::Windows::Forms::Button^ translatedVoiceButton;






	protected:

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
			this->HEADER = (gcnew System::Windows::Forms::Label());
			this->textToBeVoiced = (gcnew System::Windows::Forms::TextBox());
			this->VoiceButton = (gcnew System::Windows::Forms::Button());
			this->StopButton = (gcnew System::Windows::Forms::Button());
			this->Output = (gcnew System::Windows::Forms::Label());
			this->TranslatorButton = (gcnew System::Windows::Forms::Button());
			this->translatedVoiceButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// HEADER
			// 
			this->HEADER->AutoSize = true;
			this->HEADER->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HEADER->Location = System::Drawing::Point(220, 9);
			this->HEADER->Name = L"HEADER";
			this->HEADER->Size = System::Drawing::Size(296, 25);
			this->HEADER->TabIndex = 0;
			this->HEADER->Text = L"Tagalog to English Translator";
			this->HEADER->Click += gcnew System::EventHandler(this, &TTS::label1_Click);
			// 
			// textToBeVoiced
			// 
			this->textToBeVoiced->Location = System::Drawing::Point(13, 49);
			this->textToBeVoiced->Multiline = true;
			this->textToBeVoiced->Name = L"textToBeVoiced";
			this->textToBeVoiced->Size = System::Drawing::Size(332, 234);
			this->textToBeVoiced->TabIndex = 1;
			// 
			// VoiceButton
			// 
			this->VoiceButton->Location = System::Drawing::Point(266, 309);
			this->VoiceButton->Name = L"VoiceButton";
			this->VoiceButton->Size = System::Drawing::Size(75, 33);
			this->VoiceButton->TabIndex = 2;
			this->VoiceButton->Text = L"Voice";
			this->VoiceButton->UseVisualStyleBackColor = true;
			this->VoiceButton->Click += gcnew System::EventHandler(this, &TTS::VoiceButton_Click);
			// 
			// StopButton
			// 
			this->StopButton->Location = System::Drawing::Point(605, 309);
			this->StopButton->Name = L"StopButton";
			this->StopButton->Size = System::Drawing::Size(75, 33);
			this->StopButton->TabIndex = 4;
			this->StopButton->Text = L"Stop";
			this->StopButton->UseVisualStyleBackColor = true;
			this->StopButton->Click += gcnew System::EventHandler(this, &TTS::StopButton_Click);
			// 
			// Output
			// 
			this->Output->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Output->Location = System::Drawing::Point(361, 49);
			this->Output->Name = L"Output";
			this->Output->Size = System::Drawing::Size(319, 234);
			this->Output->TabIndex = 5;
			this->Output->Click += gcnew System::EventHandler(this, &TTS::label1_Click_1);
			// 
			// TranslatorButton
			// 
			this->TranslatorButton->Location = System::Drawing::Point(423, 309);
			this->TranslatorButton->Name = L"TranslatorButton";
			this->TranslatorButton->Size = System::Drawing::Size(93, 33);
			this->TranslatorButton->TabIndex = 6;
			this->TranslatorButton->Text = L"Translate";
			this->TranslatorButton->UseVisualStyleBackColor = true;
			this->TranslatorButton->Click += gcnew System::EventHandler(this, &TTS::TranslatorButton_Click);
			// 
			// translatedVoiceButton
			// 
			this->translatedVoiceButton->Location = System::Drawing::Point(525, 309);
			this->translatedVoiceButton->Name = L"translatedVoiceButton";
			this->translatedVoiceButton->Size = System::Drawing::Size(74, 33);
			this->translatedVoiceButton->TabIndex = 7;
			this->translatedVoiceButton->Text = L"Voice";
			this->translatedVoiceButton->UseVisualStyleBackColor = true;
			this->translatedVoiceButton->Click += gcnew System::EventHandler(this, &TTS::translatedVoiceButton_Click);
			// 
			// TTS
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(699, 354);
			this->Controls->Add(this->translatedVoiceButton);
			this->Controls->Add(this->TranslatorButton);
			this->Controls->Add(this->Output);
			this->Controls->Add(this->StopButton);
			this->Controls->Add(this->VoiceButton);
			this->Controls->Add(this->textToBeVoiced);
			this->Controls->Add(this->HEADER);
			this->Name = L"TTS";
			this->Text = L"ToE";
			this->Load += gcnew System::EventHandler(this, &TTS::TTS_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void VoiceButton_Click(System::Object^ sender, System::EventArgs^ e) {

		//i-voice ang inputted text
		voice_synthesizer.SpeakAsyncCancelAll();
		voice_synthesizer.SpeakAsync(textToBeVoiced->Text);
	}
	private: System::Void StopButton_Click(System::Object^ sender, System::EventArgs^ e) {

		voice_synthesizer.SpeakAsyncCancelAll();
	}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {


	}
	private: System::Void TranslatorButton_Click(System::Object^ sender, System::EventArgs^ e) {

		//word storage
		std::map<std::string, std::string> wordTranslations = {
			{"maganda", "pretty"},
			{"magandang_umaga", "good morning"},
			{"magandang_hapon", "good afternoon"},
			{"magandang_gabi", "good evening"}
			//...
		};

		//user input (word nga i-translate)
		String^ inputText = textToBeVoiced->Text;

		// Convert System::String^ to std::string
		std::string inputStr;
		for (int i = 0; i < inputText->Length; i++) {
			if ((char)inputText[i] == ' ') {
				inputStr += '_';
			}
			else {
				inputStr += (char)inputText[i];
			}
			
		}

		// Tokenize the input text into words
		std::istringstream iss(inputStr);
		std::string word;
		std::string translatedText;

		// Translation process
		while (iss >> word) {
			//word checker (if existing ba ang word inputted)
			auto it = wordTranslations.find(word);
			if (it != wordTranslations.end()) {
				// If the word exists, i-display ang translation
				translatedText += it->second + " ";
			}
			else {
				// If does not exist, display nga walay translation
				translatedText = "No translation for this word.";
			}
		}

		//i-display sa label ang output
		Output->Text = gcnew String(translatedText.c_str());
		}
	
	private: System::Void translatedVoiceButton_Click(System::Object^ sender, System::EventArgs^ e) {

		//i-voice and translated text
		voice_synthesizer.SpeakAsync(Output->Text);
	}
	private: System::Void TTS_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
