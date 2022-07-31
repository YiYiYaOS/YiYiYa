#include "mp.h"

// muti process init
void mp_init() {
#ifdef MP_ENABLE
  int cpu_nums = cpu_get_number();
  int current_cpu_id = cpu_get_id();

  // init cpu
  for (int i = 0; i < cpu_nums; i++) {
    int id = cpu_get_index(i);
    if (current_cpu_id != id) {
      cpu_init_id(id);
    }
  }

  // delay
  cpu_delay(200);

  u32 entry=0x2000;

  // start all cpu
  for (int i = 0; i < cpu_nums; i++) {
    int id = cpu_get_index(i);
    if (current_cpu_id != id) {
      //启动cpu
      cpu_start_id(id,entry);
    }
  }

  cpu_delay(200);

#endif
}