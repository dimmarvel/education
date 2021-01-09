#include "msoftcon.h"
#include <iostream>

//Пример работы функции со структурой данных

using namespace std;

struct circle { //графический объект круг
	int xCo, yCo; // координаты центра
	int radius;
	color fillcolor; // цвет
	fstyle fillstyle; //стиль

};

void circ_draw(circle c) {
	set_color(c.fillcolor); // установка цвета
	set_fill_style(c.fillstyle); // установка стиля заполнения
	draw_circle(c.xCo, c.yCo, c.radius); //рисование круга
}

int main() {
	init_graphics();
	//создание графики
	circle c1 = { 15, 7, 5, cBLUE, X_FILL };
	circle c2 = { 41, 12, 7, cRED, O_FILL };
	circle c3 = { 65, 18, 4, cGREEN, MEDIUM_FILL };
	//рисование кругов функцией
	circ_draw(c1);
	circ_draw(c2);
	circ_draw(c3);
	set_cursor_pos(1, 25);
	cout << endl;
	system("pause");
}
