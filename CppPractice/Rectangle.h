#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
public:
	explicit Rectangle(float = 1.0, float = 1.0); //default constructor

	float perimeter();
	float area();
	float getLength() const;
	float getWidth() const;
	void setLength(float);
	void setWidth(float);
	void printDetails();
private:
	float length;
	float width;
};

#endif
