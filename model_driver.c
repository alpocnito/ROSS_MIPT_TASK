#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#include "ross.h"
#include "model.h"

//////////////////////////////// DEBUG /////////////////////////////////////////
//#define MY_DEBUG

void delay(int number_of_milliseconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + number_of_milliseconds)
        ;
}

#ifdef MY_DEBUG
#define debug_tw_event_send(e); \
        do { \
          printf("----- NEW EVENT -----\n");\
          printf("Line: %d\n", __LINE__);\
          printf("---------------------\n");\
          tw_event_send(e); \
        } while(0);
#else
#define debug_tw_event_send(e); tw_event_send(e);
#endif            

//////////////////////////////// ROBOT /////////////////////////////////////////

void robot_init(RobotState *s, tw_lp *lp)
{
  int self = lp->gid;

  s->x = g_robots.data[self-1].x;
  s->y = g_robots.data[self-1].y;
  s->package_id = 0;
  s->charge = g_robots.data[self-1].charge;
  s->look_direction = g_robots.data[self-1].look_direction;
  
  printf("Created new robot with id: %d \n", self);
  printf("\t x = %d\n", s->x);
  printf("\t y = %d\n", s->y);
  printf("\t package_id = %d\n", s->package_id);
  printf("\t charge = %d\n", s->charge);
  printf("\t look_direction = %d\n\n", s->look_direction);
}

void robot_prerun(RobotState *s, tw_lp *lp)
{
  return;
}

void robot_event_handler(RobotState *s, tw_bf *bf, message *in_msg, tw_lp *lp)
{
  int self = lp->gid;
  tw_stime ts = 1;

  printf("Robot with id = %d get new event: \n", self);
  printf("\t msgType = %d\n", in_msg->type);
  printf("\t event_type = %d\n", in_msg->body.c_r.event_type);
  printf("\t direction = %d\n", in_msg->body.c_r.direction);
  printf("\t angle = %d\n", in_msg->body.c_r.angle);
  printf("\t time = %d\n\n", in_msg->body.c_r.time);
}

void robot_RC_event_handler(RobotState *s, tw_bf *bf, message *in_msg, tw_lp *lp)
{
  printf("I have not implemented robot_RC_event_handler\n");
  abort();
}

void robot_final(RobotState *s, tw_lp *lp)
{
  int self = lp->gid;
  printf("Robot with id: %d ended simulation\n", self);
  printf("\t x = %d\n", s->x);
  printf("\t y = %d\n", s->y);
  printf("\t package_id = %d\n", s->package_id);
  printf("\t charge = %d\n", s->charge);
  printf("\t look_direction = %d\n\n", s->look_direction);
}



//////////////////////////////// CENTRAL ///////////////////////////////////////

void central_init (CentralState *s, tw_lp *lp)
{
  int self = lp->gid;

  printf("Central created with gid == %d\n", self);

  printf("\e[1;1H\e[2J");
  printf("\n====================== WAREHOUSE\n");
  for (int i = 0; i < g_map.warehouse_height; ++i)
  {
    printf("|");
    for (int j = 0; j <= g_map.warehouse_width; ++j)
    {
      if (g_map.cells[i][j].robot != NULL)
      {
        if (g_map.cells[i][j].robot->charge == 0)
          printf("\033[0;33m # \033[0;37m");
        else if (g_map.cells[i][j].robot->package_id == NO_CARGO)
          printf("\033[0;32m # \033[0;37m");
        else
          printf("\033[0;31m # \033[0;37m");
      } 
      else
      {
        if (g_map.cells[i][j].type == T_LOADING_PLACE)
          printf("\033[0;34m%2d \033[0;37m", g_map.cells[i][j].type);
        else
          printf("\033[0;37m%2d \033[0;37m", g_map.cells[i][j].type);
      }
    }
    printf("|\n");
  }
  printf("======================\n");

  printf("Timetable:\n");
  printf("\t Size: %d", g_cargo_gen.timetable_size);
  for (int i = 0; i < 10; ++i)
  {
    printf("\t time: %4d; num: %2d\n", 
      g_cargo_gen.cargo_timetable[i][0], 
      g_cargo_gen.cargo_timetable[i][1]
    );
  }
  printf("\n");

  // Sending commands
  // for (unsigned i = 0; i < total_robots; ++i)
  // {
  //   tw_event *e = tw_event_new(self, 1, lp);
  //   message *msg = tw_event_data(e);
  //   msg->type = MSGT_ROBOT_TO_CENTRAL;
  //   msg->body.r_c.robot_id = i+1;
  //   msg->body.r_c.status = COMMAND_COMPLETED;
  //   debug_tw_event_send(e);
  // }
}

void central_prerun (CentralState *s, tw_lp *lp)
{;}

void central_event_handler(CentralState *s, tw_bf *bf, message *in_msg, tw_lp *lp)
{
  int self = lp->gid;
  tw_stime ts = 1;

  printf("Central get new event: \n");
  printf("\t msgType = %d\n", in_msg->type);
  printf("\t robot_id = %d\n", in_msg->body.r_c.robot_id);
  printf("\t status = %d\n", in_msg->body.r_c.status);
}

void central_RC_event_handler(CentralState *s, tw_bf *bf, message *in_msg, tw_lp *lp)
{
  printf("I have not implemented central_RC_event_handler\n");
  abort();
}

void central_final(CentralState *s, tw_lp *lp)
{
  int self = lp->gid;
  //printf("Central: %d, last cargo:%d\n", self, s->current_cargo);
}