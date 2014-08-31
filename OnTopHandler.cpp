/* This simple application serves as a test for the "on top"
 * window handler.  For more information, see the accompanying
 * "OnTopHandler.hpp" file, or take a look at:
 * http://people.netscape.com/law/samples/index.html
 *
 * requires IBM VisualAge C++ version 3.0+ for OS/2 Warp v4.0+
 *
 * compile with:  icc.exe /Gm /B"/pm:pm" ontophandler.cpp
 */

#include <iapp.hpp>     // IApplication
#include <iframe.hpp>   // IFrameWindow

// include the "on top" handler
#include "OnTopHandler.hpp"

int main()
{
   // create a simple frame window
   IFrameWindow frame("On Top Test");

   // create an instance of the handler
   OnTopHandler handler;

   // tell the handler to handle events for our window
   handler.handleEventsFor( &frame );

   // show the window -- now just try to get something on top!
   frame.show().setFocus();

   // run the event processing until the window is closed
   IApplication::current().run();

   // tell our handler to stop event processing
   handler.stopHandlingEventsFor( &frame );

   return 0;
}

