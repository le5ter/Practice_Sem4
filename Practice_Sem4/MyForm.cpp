#include "MyForm.h"
#include <Windows.h>

using namespace PracticeSem4;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);     
    Application::Run(gcnew MyForm);
    return 0;
}

int main(array<String^>^ args)
{


    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
    PracticeSem4::MyForm form;
    Application::Run(% form);
}