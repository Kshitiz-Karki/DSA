#include <stdint.h>
#include <stdio.h>

typedef enum { CAN_NOT_ATTACK, CAN_ATTACK, INVALID_POSITION } attack_status_t;

typedef struct {
   uint8_t row;
   uint8_t column;
} position_t;

attack_status_t can_attack(position_t queen_1, position_t queen_2){
  if((queen_1.row == queen_2.row && queen_1.column == queen_2.column) || queen_1.row > 7 || queen_2.row > 7 || queen_1.column > 7 || queen_2.column > 7)
    return INVALID_POSITION;

  if(queen_1.row == queen_2.row || queen_1.column == queen_2.column || abs(queen_1.row - queen_2.row) == abs(queen_1.column - queen_2.column))
    return CAN_ATTACK;

  return CAN_NOT_ATTACK; 
}

int main(void){
  // printf("Can attack ? : %")
  return 0;
}

