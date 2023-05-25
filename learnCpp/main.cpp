#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <stdlib.h>

class Rectangle{
	private:
		int height;
		int width;
	public:
		void setDim(int w, int h) {
		width = w;
		height = h;
	}
		void draw();
		int	getArea();
};

int Rectangle::getArea() {
	int area = Rectangle::width * Rectangle::height;
	return area;
}

void	Rectangle::draw() {
	int i = 0;

	std::string edges = "+" + std::string(Rectangle::width - 2, '-') + "+";
	std::string midle = "|" + std::string(Rectangle::width - 2, ' ') + "|";

	std::cout << edges << std::endl;
	while (i < Rectangle::height) {
		std::cout << midle << std::endl;
		i++;	
	}
	std::cout << edges << std::endl;
}

int main (int argc, char *argv[])
{
	(void)argc,(void)argv;
	Rectangle rec;
	rec.setDim(strtol(argv[1], NULL, 10), strtol(argv[2], NULL, 10));
	rec.draw();
	return 0;
}

