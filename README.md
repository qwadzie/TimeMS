# TimeMS.h
microsecond and millisecond timing for code (windows native C++)
Simply include .h file, create a 'CTimeMS' object locally or globally, and call 'ShowCurrMicro('message'), GetTimeMicro(), GetTimeMS.
Use 'Start()' to start accumulative values between 'ShowCurrMicro()' calls.
ShowCurrMicro() outputs to debug window (in VS output if debugging, or use sysinternals DebugView run in administrator mode.

TODO: C++/CLI.  I think this still exists but has a new name.
Look up C++/CX and C++ UWP.
C++/CLI was a version of C++ that allowed native C++ with win32 API calls, and non-native (UWP, forms, .net, whatever...) code in the same module, in the same app.
You could switch in code between one and the other, essentially writing C# .net and native code together.
The best book to understand this, for me, was: Gordon Hogenson, C++/CLI: The Visual C++ Language for .NET, Dec 8, 2006

C#
JS?
whatever...

