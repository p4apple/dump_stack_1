#ifndef _SIGNAL_HEADLER_H_
#define _SIGNAL_HEADLER_H_

namespace dump_stack
{

// Install a signal handler that will dump signal information and a stack
// trace when the program crashes on certain signals.  We'll install the
// signal handler for the following signals.
//
// SIGSEGV, SIGILL, SIGFPE, SIGABRT, SIGBUS, and SIGTERM.
//
// By default, the signal handler will write the failure dump to the
// standard error.  You can customize the destination by installing your
// own writer function by InstallFailureWriter() below.
//
// Note on threading:
//
// The function should be called before threads are created, if you want
// to use the failure signal handler for all threads.  The stack trace
// will be shown only for the thread that receives the signal.  In other
// words, stack traces of other threads won't be shown.
 void InstallFailureSignalHandler();

// Installs a function that is used for writing the failure dump.  "data"
// is the pointer to the beginning of a message to be written, and "size"
// is the size of the message.  You should not expect the data is
// terminated with '\0'.
 void InstallFailureWriter(
					       void (*writer)(const char* data, int size));

}

#endif
