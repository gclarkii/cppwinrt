/*
A simple console app to replace the one at 
https://msdn.microsoft.com/en-us/magazine/mt745094.aspx 
which no longer works and does not used Standard C++.
Changes:
changed initilize() to winrt::init_apartment()
changed to use iostreams (insted of printf) with 
std::wstring as mentioned at https://github.com/Microsoft/cppwinrt/issues/128
and std::wcout
*/

#pragma comment(lib, "windowsapp")
#include <iostream>
#include "winrt/Windows.Foundation.h"
#include "winrt/Windows.Web.Syndication.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Web::Syndication;

int main(void) {

    winrt::init_apartment();
    Uri uri( L"http://kennykerr.ca/feed" );
    SyndicationClient client;
    SyndicationFeed feed = client.RetrieveFeedAsync( uri ).get();
    
    for ( SyndicationItem item : feed.Items() ) {
        std::wstring title = item.Title().Text();
        std::wcout << title << std::endl;
    }

    return 0;
}
