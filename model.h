//The header file template for a ROSS model
//This file includes:
// - the state and message structs
// - extern'ed command line arguments
// - custom mapping function prototypes (if needed)
// - any other needed structs, enums, unions, or #defines

#ifndef _model_h
#define _model_h

#include "ross.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>
#include <assert.h>

#define MAP_WAREHOUSE_CARGO_UNLOADING_PLACE_MAX_NUM 100
#define MAP_WAREHOUSE_CARGO_UNLOADING_PLACE_MIN_NUM 10
#define MAX_WAREHOUSE_HEIGHT 50
#define MAX_WAREHOUSE_WIDTH 50

#define MAX_COMMAND_LENGTH 100  // commands for one robot
#define MAX_CARGO_NUMBER 10000
// package_id == NO_CARGO, then robot does not have any cargo
#define NO_CARGO 6666
#define MAX_ROBOTS 100
#define MAX_PATH_STRING_LENGTH 100

extern char CONFIG_PATH[MAX_PATH_STRING_LENGTH];
extern char CONFIG_SIM_NAME[MAX_PATH_STRING_LENGTH];
extern char CONFIG_MAP_PATH[MAX_PATH_STRING_LENGTH];
extern char CONFIG_DROP_BOX_PATH[MAX_PATH_STRING_LENGTH];
extern char CONFIG_ROBOT_PATH[MAX_PATH_STRING_LENGTH];
extern char CONFIG_PACKAGE_PATH[MAX_PATH_STRING_LENGTH];
extern char CONFIG_LOGGING_PATH[MAX_PATH_STRING_LENGTH];

// Constants of the simulation. All times in second
extern int    ModelConfigZoneSize;
extern int    ModelConfigUnitSize;
extern int    ModelConfigSafeUnitSize;
extern float  ModelConfigUnitSpeed;
extern float  ModelConfigUnitAccelerationTime;
extern float  ModelConfigUnitStopTime;
extern float  ModelConfigUnitRotateTime;
extern float  ModelConfigUnitAccelerationEnergy;
extern float  ModelConfigUnitMoveEnergy;
extern float  ModelConfigUnitRotateEnergy;
extern float  ModelConfigLoadTime;
extern float  ModelConfigUnloadTime;
extern float  ModelConfigUnitLoadEnergy;
extern float  ModelConfigUnitUnloadEnergy;
extern float  ModelConfigUnitWaitEnergy;
extern float  ModelConfigUnitChargeTime;
extern double ModelConfigUnitChargeValue;
extern float  ModelConfigUnitCount;

extern int total_robots;
extern int total_centrals;

typedef enum
{
  A_0,
  A_90,
  A_180,
  A_270,
} Angle;

typedef enum {
  D_UP    = 0,
  D_DOWN  = 1,
  D_LEFT  = 2,
  D_RIGHT = 3,
} Direction;

typedef enum {
  T_EMPTY = 0,
  T_WALL = 1,
  T_LOADING_PLACE = 2,
  T_UNLOADING_PLACE = 3, 
  T_CHARGE_STATION = 4,
  T_UNKNOWN = 5
} TileType; 

typedef enum
{
  MSGT_ROBOT_TO_CENTRAL,
  MSGT_CENTRAL_TO_ROBOT
} msgType;

typedef enum
{
  EVENT_WAIT,
  EVENT_MOVE,
  EVENT_ROUND
} robotEventType;

typedef enum
{
  COMMAND_COMPLETED,
  COMMAND_FAILED,
} statusCode;

enum lpTypeVals
{
  TYPE_CENTRAL = 0,
  TYPE_ROBOT = 1
};

typedef struct{
  int x;
  int y;
  unsigned package_id; // id_in_line
  float charge;
  Direction look_direction;
} RobotState;

typedef struct {
  RobotState data[MAX_ROBOTS];
  unsigned N;
} Robots;

typedef struct {
  int x;
  int y;
  TileType type;
  RobotState* robot;
} Cell;

typedef struct { 
  int warehouse_height;
  int warehouse_width;

  Cell cells[MAX_WAREHOUSE_HEIGHT][MAX_WAREHOUSE_WIDTH];
} CentralState;

typedef struct
{
  // cargo_timetable[i][0] - arrival of cargo in offset from simulation start
  // cargo_timetable[i][1] - id of direction to send cargo
  unsigned cargo_timetable [MAX_CARGO_NUMBER][2]; // cargo_id -> [time, direction_id]
  unsigned timetable_size;

  unsigned current_cargo;
  unsigned num_cargo_in_wait;
  unsigned num_cargo_received;
} CargoGenerator;

typedef struct
{
  msgType type;
  union
  {
    // Robot to central message
    struct 
    {
      tw_lpid robot_id;
      statusCode status;
    } r_c;

    // Central to robot message
    struct 
    {
      robotEventType event_type;
      Direction direction;
      Angle angle;
      tw_stime time;
    } c_r;

  } body;
} message;

// global variables
CentralState g_map;
Robots g_robots;
CargoGenerator g_cargo_gen;

extern tw_lpid lpTypeMapper(tw_lpid gid);
extern tw_peid model_map(tw_lpid gid);

extern void robot_init(RobotState *s, tw_lp *lp);
extern void robot_prerun(RobotState *s, tw_lp *lp);
extern void robot_event_handler(RobotState *s, tw_bf *bf, message *in_msg, tw_lp *lp);
extern void robot_RC_event_handler(RobotState *s, tw_bf *bf, message *in_msg, tw_lp *lp);
extern void robot_final(RobotState *s, tw_lp *lp);
extern void robot_commit(RobotState *s, tw_bf *bf, message *m, tw_lp *lp);

extern void central_init(CentralState *s, tw_lp *lp);
extern void central_prerun(CentralState *s, tw_lp *lp);
extern void central_event_handler(CentralState *s, tw_bf *bf, message *in_msg, tw_lp *lp);
extern void central_RC_event_handler(CentralState *s, tw_bf *bf, message *in_msg, tw_lp *lp);
extern void central_final(CentralState *s, tw_lp *lp);
extern void central_commit(CentralState *s, tw_bf *bf, message *m, tw_lp *lp);

extern tw_lptype model_lps[];
unsigned int custom_LPs_per_pe;

extern void read_config(char* path);
extern void read_robots(char* path);
extern void read_map(char* path);
extern void read_cargo(char* path);

extern void PrintMap();
extern void RobotsPrint();

#endif
