/**
 
Copyright (c) 2014-2015 National Instruments Corp.
 
This software is subject to the terms described in the LICENSE.TXT file
 
SDG
*/

/*! \file
 */

#include <stdio.h>
#include "TypeAndDataManager.h"
#include "EventLog.h"

using namespace Vireo;

//------------------------------------------------------------
StringRef EventLog::DevNull = (StringRef) null;
StringRef EventLog::StdOut = (StringRef) 1;

//------------------------------------------------------------
EventLog::EventLog(StringRef string)
{
    _errorLog = string;
    _softErrorCount = 0;
    _hardErrorCount = 0;
    _warningCount = 0;
}
//------------------------------------------------------------
void EventLog::LogEventV(EventSeverity severity, Int32 lineNumber, ConstCStr message, va_list args)
{
    char buffer[200];
    
    vsnprintf (buffer, sizeof(buffer), message, args);
    LogEventCore( severity, lineNumber, buffer);
}
//------------------------------------------------------------
void EventLog::LogEvent(EventSeverity severity, Int32 lineNumber, ConstCStr message, ...)
{
    char buffer[200];
    
    va_list args;
    va_start (args, message);
    vsnprintf (buffer, sizeof(buffer), message, args);
    va_end (args);
    
    LogEventCore( severity, lineNumber, buffer);
}
//------------------------------------------------------------
void EventLog::LogEventCore(EventSeverity severity, Int32 lineNumber, ConstCStr message)
{
    char buffer[200];
    ConstCStr preamble;
    
    switch (severity) {
        case kWarning:
            preamble = "Warning";
            break;
        case kSoftDataError:
            preamble = "Error";
            _softErrorCount++;
            break;
        case kHardDataError:
            preamble = "HardError";
            _hardErrorCount++;
            break;
        case kTrace:
        default:
            preamble = "Trace";
            break;
    }
    
    if (_errorLog == DevNull)
        return;
    
    Int32 length;
    if (lineNumber > 0) {
        length = snprintf(buffer, sizeof(buffer), "(Line %d %s \"%s.\")\n", (int)lineNumber, preamble, message);
    } else {
        length = snprintf(buffer, sizeof(buffer), "(%s \"%s.\")\n", preamble, message);
    }
    
    if (_errorLog == StdOut) {
        gPlatform.IO.Print(buffer);
    } else if (_errorLog) {
        _errorLog->Append(length, (const Utf8Char*)buffer);
    }
}

#if 0
DEFINE_VIREO_BEGIN(EventLog)
    DEFINE_VIREO_FUNCTION(EventLogRecordEvent, "p(i(.String))")
DEFINE_VIREO_END()
#endif
