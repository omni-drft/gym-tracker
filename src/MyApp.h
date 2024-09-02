#pragma once

#include <wx/wx.h>
#include <SQLiteCpp/SQLiteCpp.h>

#include "MyFrame.h"

class MyApp : public wxApp
{
public:
    bool OnInit() override;
};