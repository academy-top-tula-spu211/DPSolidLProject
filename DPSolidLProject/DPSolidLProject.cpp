// DPSolidLProject.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <typeinfo>

class IFigure
{
public:
    virtual int GetWidth() = 0;
    virtual int GetHeight() = 0;

    virtual void SetWidth(int width) = 0;
    virtual void SetHeight(int height) = 0;
    virtual int Area() = 0;
};

class Rectangle : public IFigure
{
protected:
    int width;
    int height;
public:
    Rectangle(int width = 0, int height = 0)
        : width{ width }, height{ height } {}

    int GetWidth() override { return this->width; }
    int GetHeight() override { return this->height; }
    
    void SetWidth(int width) override { this->width = width; }
    void SetHeight(int height) override { this->height = height; }

    int Area() override { return width * height; }
};

class Square : public IFigure
{
    int side;
public:
    Square(int side = 0) : side{ side } {}

    int GetWidth() override { return this->side; }
    int GetHeight() override { return this->side; }

    void SetWidth(int side) override
    {
        this->side = side;
    }

    void SetHeight(int side) override
    {
        this->side = side;
    }

    int Area() override { return side * side; }
};


void TestRectangleArea(IFigure* figure)
{
    if (typeid(*figure) == typeid(Rectangle))
    {
        figure->SetWidth(10);
        figure->SetHeight(20);
        if (figure->Area() != 200)
            std::cout << "error\n";
        else
            std::cout << "not error\n";
    }
    else
    {
        figure->SetHeight(20);
        if (figure->Area() != 400)
            std::cout << "error\n";
        else
            std::cout << "not error\n";
    }
    
}

int main()
{
    TestRectangleArea(new Rectangle());
    TestRectangleArea(new Square());
}

