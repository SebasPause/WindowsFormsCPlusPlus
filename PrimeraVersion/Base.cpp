#include "Base.h"
#include "PrimeraVersionLib.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PrimeraVersion::Base base;
	Application::Run(% base);
}