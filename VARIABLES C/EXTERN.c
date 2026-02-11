EXTERN

- Ejemplo1: Supongamos que tengo un KEYPAD.h, KEYPAD.c y un main.c  
- Si tengo una variable "int tecla;" dentro del KEYPAD.c y quiero usarlo en el main.c, entonces debo declarar
  "extern int tecla;" en el main.c y de esta manera puedo usar esta varible tanto en el main.c y el KEYPAD.c sin problemas

- Ejemplo2: Supongamos que tengo un LCD.h, LCD.c y un main.c  
- Si tengo un variable "I2C_HandleTypeDef hi2c1;" en el main.c y quiero usarlo en LCD.c, puedo hacer dos cosas:
  - Ya que el LCD.c va de la mano con el LCD.h, puedo declarar "extern I2C_HandleTypeDef hi2c1;" en el LCD.c ó LCD.h
  - Pero por motivos de organizacion debo colocar el "extern I2C_HandleTypeDef hi2c1;" en el LCD.h