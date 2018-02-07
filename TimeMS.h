/*
 *  \file TimeMS.h
 *  \brief High Resolution timer CTimeMS class
 */

#ifndef TIMEMS_H
#define TIMEMS_H
//////////////////////////////////////////////////////////////////////////////
/*! 
 * \brief Return current millisecond time from the OS.
 *
 * Use whatever OS call, in Win32, uses high-performance frequency timer.
 * long GetTimeMS()	:	Get current millisecond counter from operating-system.
 *
 */
class CTimeMS
{
private:
  LARGE_INTEGER liTicksPerSec;
	LARGE_INTEGER liTime,liTickPerMicro,liTickPerMS;
  LONGLONG liStartMicro,liStartMS;
  static LONGLONG llPrevMicro;
public:
  CTimeMS::CTimeMS()
  {
    QueryPerformanceFrequency(&liTicksPerSec);
    liTickPerMicro.QuadPart  = liTicksPerSec.QuadPart/1000000L;
    liTickPerMS.QuadPart     = liTicksPerSec.QuadPart/1000;
    Start();
  }
	long GetTimeMS()
	{
		QueryPerformanceCounter(&liTime);
		// get elapsed time
		if (liTickPerMS.QuadPart!=0)
			return  (long)(liTime.QuadPart / liTickPerMS.QuadPart);
		else
			return 0L;
	}
	LONGLONG GetTimeMicro()
	{
		QueryPerformanceCounter(&liTime);
		// get elapsed time
		if (liTickPerMicro.QuadPart!=0)
    {
			return  (liTime.QuadPart / liTickPerMicro.QuadPart);
    }
		else
			return 0L;
	}
  void Start()
  {
    liStartMicro  = GetTimeMicro();
    liStartMS     = GetTimeMS();
    if (llPrevMicro==-1)
      llPrevMicro = liStartMicro;
  }
  void ShowCurrMicro(char *msg)
  {
    static char defaultbuf[20] = "Micro";
    if (msg==0)
    {
      msg = &defaultbuf[0];
    }
    LONGLONG llCurr = GetTimeMicro();
    LONGLONG llTimeLast = llCurr - llPrevMicro;
    llPrevMicro = llCurr;
    long lCurr = static_cast<long>(llCurr);
    char buf[256];
    sprintf_s(buf, "%10s:%ld:Len:%ld",msg,lCurr,static_cast<long>(llTimeLast));
    ::OutputDebugStringA(buf);
  }
  void Show(char *msg)
  {
    ShowCurrMicro(msg);
  }
};

LONGLONG CTimeMS::llPrevMicro = -1;


#endif
