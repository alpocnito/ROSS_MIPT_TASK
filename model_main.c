// The C main file for a ROSS model
// This file includes:
//  - definition of the LP types
//  - command line argument setup
//  - a main function

#include "model.h"

tw_lptype model_lps[] =
{
  {
    (init_f) central_init,
    (pre_run_f) central_prerun,
    (event_f) central_event_handler,
    (revent_f) central_RC_event_handler,
    (commit_f) NULL,
    (final_f) central_final,
    (map_f) model_map,
    sizeof(CentralState)
  },
  {
    (init_f) robot_init,
    (pre_run_f) robot_prerun,
    (event_f) robot_event_handler,
    (revent_f) robot_RC_event_handler,
    (commit_f) NULL,
    (final_f) robot_final,
    (map_f) model_map,
    sizeof(RobotState)
  },
  { 0 },
};

int total_robots = 0;
int total_centrals = 1;

const tw_optdef model_opts[] = {
    TWOPT_GROUP("ROSS Model"),
    TWOPT_END(),
};

void displayModelSettings()
{
  if (g_tw_mynode == 0)
  {
    for (int i = 0; i < 30; i++)
      printf("*");
    
    printf("\n");
    printf("Model Configuration:\n");
    printf("\t nnodes: %i\n", tw_nnodes());
    printf("\t g_tw_nlp: %llu\n", g_tw_nlp);
    printf("\t total_robots: %i\n", total_robots);
    printf("\t total_centrals: %i\n\n", total_centrals);
    printf("\t CONFIG_PATH: %s\n", CONFIG_PATH);
    printf("\t CONFIG_MAP_PATH: %s\n", CONFIG_MAP_PATH);
    printf("\t CONFIG_PACKAGE_PATH: %s\n", CONFIG_PACKAGE_PATH);
    printf("\t CONFIG_ROBOT_PATH: %s\n", CONFIG_ROBOT_PATH);

    for (int i = 0; i < 30; i++)
      printf("*");
    
    printf("\n");
  }
}

int main(int argc, char *argv[])
{
  // Loading configs
  tw_opt_add(model_opts);
  tw_init(&argc, &argv);

  read_config(CONFIG_PATH);
  read_map(CONFIG_MAP_PATH);
  read_cargo(CONFIG_PACKAGE_PATH);
  read_robots(CONFIG_ROBOT_PATH);

  displayModelSettings();
  PrintMap();
  RobotsPrint();

  // Starting simulation
  g_tw_nlp = total_robots + total_centrals;  
  displayModelSettings();
  g_tw_lp_types = model_lps;
  g_tw_lp_typemap = lpTypeMapper;

  tw_define_lps(g_tw_nlp, sizeof(message));
  tw_lp_setup_types();
  tw_run();
  tw_end();

  return 0;
}
