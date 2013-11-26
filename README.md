at2
===

Utility to run a program at a specified time, with microsecond level resolution (depending on scheduler :) )

Usage : at2 <base_time> <delta_time_s> cmd [cmd_arg1] [[cmd_arg2]..]
base_time is designed to take input directly from $(date --rfc-3339=ns), which enables usage like the following

    base_time = $(date --rfc-3339=ns)

    at2 base_time 5 twiddle_gpio &
    at2 base_time 6 twiddle_gpio &




Dependencies
===
boost - ya, used for posix time and time conversion.  Probably should convert it to c++11 using chronos at some point.
  * libboost-thread-dev
  * libboost-dev


General notes
===
TODO: 
  * Enhance command line processing to utilize more friendly command line options.  
  * The delta time could be better specified to handle a wider variety of use cases, but I have yet to encounter one that requires specifying the run time with less than second precision.  Normally it should be enough to run the set of things at some point in the future at almost the exact same time.
