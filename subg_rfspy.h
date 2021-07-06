#ifndef SUBG_RFSPY_H
#define SUBG_RFSPY_H

#include <stdbool.h>

void subg_rfspy_main();

extern bool __xdata subg_rfspy_init_finished;
extern bool __xdata subg_rfspy_should_exit;
//extern bool __xdata in_a_command;

#endif // SUBG_RFSPY_H
