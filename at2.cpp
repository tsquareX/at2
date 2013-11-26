/*
 * at2.cpp
 *
 *  Created on: Nov 19, 2013
 *      Author: tom
 */

#include <sys/timeb.h>

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp>

using namespace boost::gregorian;
using namespace boost::posix_time;
using namespace std;

string usage("Usage : at2 base_time delta_time cmd [cmd_arg1] [[cmd_arg2]..]");

/**
 * Run program at specified time (microsecond precision).
 * Usage :
 *
 * at2 <time> <delta> <cmd> <cmd_arg_1> <cmd_arg_2> ...
 */
int main(int argc, char *argv[]) {

	if(argc < 4) {
		cout << usage << endl;
		return EXIT_FAILURE;
	}

	string at_time_arg(argv[1]);
	string delta_time_arg(argv[2]);

	/*
	 * Concatenate command
	 */
	string cmd(argv[3]);
	for(int i=4; i < argc; i++) {
		cmd += string(" ") + argv[i];
	}

	/*
	 * Figure out time to run.
	 */
	ptime at_time = time_from_string(at_time_arg);
	unsigned int sec;
	sscanf(delta_time_arg.c_str(), "%u", &sec);
	ptime run_time = at_time + seconds(sec);

	ptime cur_time = microsec_clock::local_time();
	time_duration sleep_time = run_time - cur_time;

	cout << "Command enqueued to run at : " << to_simple_string(run_time) << endl;
	cout << "Sleeping for : " << sleep_time << endl;

	/*
	 * Delay
	 */
	boost::this_thread::sleep(sleep_time);

	/*
	 * Run the command
	 */

	int ret = system(cmd.c_str());

	return ret;
}
