#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H

#include "Model.h"

//for do_go_command, do_run_command, and do_stop command I passed it a char for the mode to decide if the computer is controling the
//objects or the person is.

//

void do_move_command(Model& model, char mode, int id, double x, double y);

void do_work_a_depot_command(Model& model, int id1, int id2);

void do_deposit_moon_stones_command(Model& model, int id1, int id2);

void do_heal_command(Model& model, int id1, int id2);

void do_stop_command(Model& model, char mode, int id);

void do_lock_in_at_station_command(Model& model, int id1, int id2);

void do_attack_command(Model& model, int id1, int id2);

void do_go_command(Model& model, char mode);

void do_run_command(Model& model, char mode);

void do_quit_command(Model& model);





#endif
