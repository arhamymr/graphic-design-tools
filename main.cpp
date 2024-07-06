#include <wx/wx.h>
#include <wx/button.h>

class MyApp : public wxApp
{
  public: bool OnInit() override;
};

class MyFrame : public wxFrame
{
  private: 
    bool isMaximized;
  public: 
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    void Expand() {
      if (!isMaximized){
        Maximize();
        isMaximized = true;
      } else {
        Restore();
        isMaximized = false;
      }
    }
};

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    // Create a panel with a label "Hello World"
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    new wxStaticText(panel, wxID_ANY, wxT("Hello World"), wxPoint(10, 10), wxDefaultSize, 0);

    // Create Button 
    wxButton* button = new wxButton(panel, wxID_ANY, wxT("Click Me"), wxPoint(10,50), wxDefaultSize);
    button->Bind(wxEVT_BUTTON, this->Expand());
}

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame("Hello World", wxDefaultPosition, wxSize(450, 350));
    frame->Show(true);
    frame->Expand();
    return true;
}

wxIMPLEMENT_APP(MyApp);