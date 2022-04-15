#include <windows.h>
#include <stdio.h>
#include <time.h>

const static int Text_Color_table[] = {
 FOREGROUND_BLUE,   //0藍色
 FOREGROUND_GREEN,  //1綠色
 FOREGROUND_RED,    //2紅色
 FOREGROUND_BLUE | FOREGROUND_GREEN, //3藍綠色
 FOREGROUND_BLUE | FOREGROUND_RED ,  //4紫色
 FOREGROUND_GREEN | FOREGROUND_RED,  //5土黃色
 FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED //6白色

};
const static int BG_Color_table[] = {
 BACKGROUND_BLUE,   //0藍色
 BACKGROUND_GREEN,  //1綠色
 BACKGROUND_RED,    //2紅色
 BACKGROUND_BLUE | BACKGROUND_GREEN, //3藍綠色
 BACKGROUND_BLUE | BACKGROUND_RED ,  //4紫色
 BACKGROUND_GREEN | BACKGROUND_RED,  //5土黃色
 BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED //6白色

};
const  static int Light_Text = FOREGROUND_INTENSITY;
const  static int Light_Background = BACKGROUND_INTENSITY;


typedef struct _Point {
 int x;
 int y;
} Point;




HANDLE console_device;
int snack_color = Text_Color_table[2] | BG_Color_table[2] | Light_Text | Light_Background;
const int g_max_x = 79;
const int g_max_y = 24;
const int g_min_x = 0;
const int g_min_y = 0;

int snake_index = 0;
enum { UP=1,DOWN,LEFT ,RIGHT };
int dir = UP;
Point table[100];
Point target_poing;

void generate_point() {

 target_poing.x = rand() % 78 + 1; //1~78
 target_poing.y = rand() % 23 + 1; //1~23
}

void init_game() {
 dir = 1;
 snake_index = 0;
 table[snake_index].x = 39;
 table[snake_index].y =12;
 generate_point();
}

void check_eat() {
    
 if (table[0].x == target_poing.x && table[0].y == target_poing.y) {
  snake_index++;  
  generate_point();
 }
  
}
bool is_dead() {

 if (table[0].x <= g_min_x || table[0].x >= g_max_x)return true;
  
 if(table[0].y <= g_min_y || table[0].y >= g_max_y)return true;

 return 0;
}


void draw_grid(int x,int y,int color) {
 COORD pos = { x, y }; 
 SetConsoleCursorPosition(console_device, pos);
 SetConsoleTextAttribute(console_device, color);
 printf(" ");
}

void clear_snake() {

draw_grid(table[snake_index].x, table[snake_index].y, 0);

}
void draw_snake() {

 for (int i = 0; i <=snake_index; i++) {
  draw_grid(table[i].x, table[i].y, snack_color);
 }

}
void update_snake() {

 int temp_x = table[0].x;
 int temp_y = table[0].y;
  
 switch (dir)
 {
 case UP:   //UP
  table[0].y -= 1;
  break;
 case DOWN:  //DOWN
  table[0].y += 1;
  break;
 case LEFT: //LEFT
  table[0].x -= 1;
  break;
 case RIGHT:  //RIGHT
  table[0].x += 1;
  break;
 }
 if (snake_index > 0) {  
      int t, t2;  //暫存往前遞補
  for (int i = 1; i <= snake_index; i++) {
   t = table[i].x;
   t2 = table[i].y;
   table[i].x = temp_x;
   table[i].y = temp_y;
   temp_x = t;
   temp_y = t2;
  }  
 }

 
}



void draw_wall() {
 //draw top
 for (int i = g_min_x; i <= g_max_x; i++)
  draw_grid(i, 0, BG_Color_table[0] | Light_Background);
 //draw bottom
 for (int i =g_min_x; i <= g_max_x; i++)
  draw_grid(i, 24, BG_Color_table[0] | Light_Background);
 //draw left
 for (int i = g_min_y; i <= g_max_y ;i++)
  draw_grid(0, i, BG_Color_table[0] | Light_Background);
 //draw right
 for (int i = g_min_y; i <= g_max_y; i++)
  draw_grid(g_max_x, i, BG_Color_table[0] | Light_Background);

}


void user_input() {
 
 if (GetAsyncKeyState(VK_UP))dir = 1;
 else if (GetAsyncKeyState(VK_DOWN)) dir = 2;
 else if (GetAsyncKeyState(VK_LEFT)) dir = 3;
 else if (GetAsyncKeyState(VK_RIGHT))dir = 4;
 
}


int main() {

 srand(time(NULL));

 console_device = GetStdHandle(STD_OUTPUT_HANDLE); //取得output device 

 clock_t time, time2;
 float time_result;
 
 /*Hide console cusor*/
 CONSOLE_CURSOR_INFO info;
 info.dwSize = 100;
 info.bVisible = FALSE;
 SetConsoleCursorInfo(console_device, &info);


 float step = 1 / 10.f; //10fps 每秒刷新10次避免CPU跑過快

 init_game();
 draw_wall();
 time = clock();
 while (true) {

  time2 = clock();
  time_result = (time2 - time)/1000.0f;
  if (time_result > step) {
   time = time2;

   clear_snake();
   check_eat();
   update_snake(); 
   draw_snake();  
   draw_grid(target_poing.x, target_poing.y, BG_Color_table[1]); 
   user_input();
   if (is_dead())break;

      }
    

 }




 return 0;
}
