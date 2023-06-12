#ifndef _SEGMENT_H_
#define _SEGMENT_H_

#include <sys/types.h>

void _segment_info(pid_t(*get_id)());
void segment_info_pid();
void segment_info_tid();

#endif // _SEGMENT_H_