#ifndef _SEGMENT_H_
#define _SEGMENT_H_

#include <sys/types.h>
#include "selector.h"
#include "../pid/pid.h"

void _segment_info(PidType_t id_type);
void segment_info_pid();
void segment_info_tid();

#endif // _SEGMENT_H_