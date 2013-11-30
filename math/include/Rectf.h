#ifndef RECTF_H_
#define RECTF_H_


namespace cph {

class Rectf {

private:
	float x, y, width, height;

public:
	Rectf(float x = 0, float y = 0, float width = 0, float height = 0);
	~Rectf();

	float getX() const;
	float getY() const;
	float getWidth() const;
	float getHeight() const;

	void setX(float x);
	void setY(float y);
	void setWidth(float width);
	void setHeight(float height);
	void setRect(float x, float y, float width, float height);

	bool operator==(const Rectf& other) const;
	bool operator!=(const Rectf& other) const;

};

}

#endif