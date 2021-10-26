#ifndef CRAPS
#define CRAPS
#define _CRT_SECURE_NO_WARNINGS
void print_game_rules(void);
double get_bank_balance(void);
double get_wager_amount(void);
double check_wager_amount(double g_wager, double bank_balance);
int roll_die(void);
int calculate_sum(int die_1, int die_2);
int is_win_loss_or_point(int v_sum);
int is_point_loss_or_neither(int v_sum, int point_val);


//void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);
